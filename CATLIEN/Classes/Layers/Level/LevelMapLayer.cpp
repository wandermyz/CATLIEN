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
USING_NS_CC;

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
    
    _primitiveLayer = LevelMapPrimitiveLayer::create();
    addChild(_primitiveLayer, LEVEL_MAP_LAYER_PRIMITIVE_Z);
    
    return true;
}

void LevelMapLayer::onEnter()
{
    CCLayer::onEnter();
    GlobalEngine::sharedGlobalEngine()->enterLevelMapLayer(this);
    GlobalEngine::sharedGlobalEngine()->switchToEditorMode();
}

void LevelMapLayer::onExit()
{
    GlobalEngine::sharedGlobalEngine()->leaveLevelMapLayer();
    
    _gameObjects->removeAllObjects();
    _gameObjects->release();
    
    CCLayer::onExit();
}

void LevelMapLayer::addElement(GameObject *gameObject)
{
    addChild(gameObject, LEVEL_MAP_LAYER_ELEMENTS_Z);
    _gameObjects->addObject(gameObject);
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
}

void LevelMapLayer::removeElement(GameObject *gameObject)
{
    deselectElement(gameObject);
    removeChild(gameObject, true);
    _gameObjects->removeObject(gameObject);
}

