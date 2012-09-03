//
//  LevelMapLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#include "cocos2d.h"
#include "LevelMapLayer.h"
#include "AnimationTexture.h"
#include "GlobalEngine.h"
#include "../../GameObjects/Planet.h"
USING_NS_CC;

#define GRAVITY_CONST 1

bool LevelMapLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    /*AnimationTexture* tex = AnimationTexture::createWithSpriteFrameName("planet_1.png");
    tex->setPosition(ccp(0,0));
    this->addChild(tex);*/
    //editorLayer->addChild(tex);
    
    _gameObjects = CCArray::create();
    _gameObjects->retain();
    
    _planets = CCArray::create();
    _planets->retain();
    
    _primitiveLayer = LevelMapPrimitiveLayer::create();
    addChild(_primitiveLayer, LEVEL_MAP_LAYER_PRIMITIVE_Z);
    
    
    _player = NULL;
    return true;
}

void LevelMapLayer::onEnter()
{
    CCLayer::onEnter();
    GlobalEngine::sharedGlobalEngine()->enterLevelMapLayer(this);
    scheduleUpdate();
    
    GlobalEngine::sharedGlobalEngine()->switchToEditorMode();
    addPlayer();
}

void LevelMapLayer::onExit()
{
    unscheduleUpdate();
    
    GlobalEngine::sharedGlobalEngine()->leaveLevelMapLayer();
    
    _planets->removeAllObjects();
    _planets->release();
    
    _gameObjects->removeAllObjects();
    _gameObjects->release();
    
    CCLayer::onExit();
}

void LevelMapLayer::addPlayer()
{
    //add player randomly
    CCAssert(_player == NULL, "Cannot add multiple players. ");    
    _player = Player::create();
    addChild(_player, LEVEL_MAP_LAYER_PLAYER_Z);
    _gameObjects->addObject(_player);
    randomizeElementPosition(_player);
}

void LevelMapLayer::addElement(GameObject *gameObject)
{
    addChild(gameObject, LEVEL_MAP_LAYER_ELEMENTS_Z);
    _gameObjects->addObject(gameObject);
    
    //handle special objects
    switch (gameObject->getType())
    {
        case GameObjectTypePlanet:
            _planets->addObject(gameObject);
            break;
            
        default:
            break;
    }
}



void LevelMapLayer::setElementPosition(GameObject *gameObject, cocos2d::CCPoint position)
{
    gameObject->setPosition(position);
}

void LevelMapLayer::randomizeElementPosition(GameObject *gameObject)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCRect bb = gameObject->boundingBox();
    
    float minX = -bb.getMinX();
    float minY = -bb.getMinY();
    float maxX = winSize.width - bb.getMaxX();
    float maxY = winSize.height - bb.getMaxY();
    
    float x = minX + CCRANDOM_0_1() * (maxX - minX);
    float y = minY + CCRANDOM_0_1() * (maxY - minY);
    
    gameObject->setPosition(ccp(x, y));
    gameObject->resetB2Body();
}

void LevelMapLayer::removeElement(GameObject *gameObject)
{
    deselectElement(gameObject);
    removeChild(gameObject, true);
    
    //handle special objects
    switch (gameObject->getType())
    {
        case GameObjectTypePlanet:
            _planets->removeObject(gameObject);
            break;
            
        case GameObjectTypePlayer:
            _player = NULL;
            break;
            
        default:
            break;
    }
    
    _gameObjects->removeObject(gameObject);
}

void LevelMapLayer::update(float deltaTime)
{
    //TODO:
    /*
     When grounded, not force by other planets
     how to clear out friction?
     */
    
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() == GameModeLevel)
    {
        //add gravity
        b2Vec2 force;
        force.SetZero();
        
        b2Body* playerBody = _player->getB2Body();
        b2Vec2 playerPos = playerBody->GetPosition();
        
        for (int i = 0; i < _planets->count(); i++)
        {
            GameObject* obj = (GameObject*)_planets->objectAtIndex(i);
            b2Vec2 planetPos = obj->getB2Body()->GetPosition();
            
            b2Vec2 offset = planetPos - playerPos;
            float scalar = playerBody->GetMass() * ((Planet*)obj)->getB2Mass() / offset.LengthSquared() * GRAVITY_CONST;  //mass = 0 for static b2body, so use our own mass computing
            
            b2Vec2 gravity;
            gravity.Set(offset.x * scalar, offset.y * scalar);
            force += gravity;
        }
        
        //rotate to gravity
        float angle = atan2(force.y, force.x) + b2_pi / 2.0f;
        playerBody->SetTransform(playerBody->GetPosition(), angle);
        
        playerBody->ApplyForceToCenter(force);
        
        //apply movement
        b2Vec2 localForce;
        switch (_player->getMoveState()) {
            case PlayerMoveStateLeft:
                localForce.Set(-PLAYER_MOVE_FORCE, 0);
                break;
                
            case PlayerMoveStateRight:
                localForce.Set(PLAYER_MOVE_FORCE, 0);
                break;
                
            default:
                localForce.SetZero();
                break;
        }
        
        b2Rot rotation(angle);
        b2Vec2 globalForce = b2Mul(rotation, localForce);
        playerBody->ApplyForceToCenter(globalForce);
        
        //b2Vec2 impulse = globalSpeed - playerBody->GetLinearVelocity();
        //impulse *= playerBody->GetMass();
        //playerBody->ApplyLinearImpulse(impulse, playerBody->GetWorldCenter());
        
        GlobalEngine::sharedGlobalEngine()->getPhysicsWorld()->step(deltaTime);
    }
}
