//
//  GameObject.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "GameObject.h"
#include "../GlobalEngine.h"
#include <string>
using namespace std;
USING_NS_CC;

GameObject::GameObject() : _name("")
{
}

bool GameObject::init()
{
    _b2Body = NULL;
    _texture = NULL;
    return true;
}

void GameObject::onEnter()
{
    CCNode::onEnter();
    createB2Body();
    scheduleUpdate();
}

void GameObject::onExit()
{
    unscheduleUpdate();
    destroyB2Body();
    CCNode::onExit();
}

bool GameObject::containsPoint(const CCPoint& p)
{
    return boundingBox().containsPoint(p);
}

void GameObject::drawSelection()
{
    ccDrawColor4B(255, 255, 255, 255);
    glLineWidth(3);
    CCRect rect = boundingBox();
    
    CCPoint vertices[] = {
        ccp(rect.getMinX(), rect.getMinY()),
        ccp(rect.getMaxX(), rect.getMinY()),
        ccp(rect.getMaxX(), rect.getMaxY()),
        ccp(rect.getMinX(), rect.getMaxY()) };
    ccDrawPoly( vertices, 4, true);
}

bool GameObject::setTexturePath(const char *texturePath)
{
    if (_texturePath == string(texturePath))
    {
        return false;
    }
    
    _texturePath = string(texturePath);
    if (_texture != NULL)
    {
        removeChild(_texture, true);
    }
    
    if (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(_texturePath.c_str()) != NULL)
    {
        _texture = AnimationTexture::createWithSpriteFrameName(_texturePath.c_str());
    }
    else
    {
        _texture = AnimationTexture::createWithSpriteFrameName("planet_x.png");
    }
    
    addChild(_texture);
    _texture->setAnchorPoint(ccp(0,0));
    
    setContentSize(_texture->getContentSize());
    setAnchorPoint(ccp(0.5, 0.5));
    
    return true;
}

void GameObject::setFrameCount(int frameCount)
{
    _frameCount = frameCount;
}

void GameObject::createB2Body()
{
    _b2Body = NULL;
}

void GameObject::destroyB2Body()
{
    if (_b2Body != NULL)
    {
        GlobalEngine::sharedGlobalEngine()->getPhysicsWorld()->destroyBody(_b2Body);
        _b2Body = NULL;
    }
}

void GameObject::resetB2Body()
{
    destroyB2Body();
    createB2Body();
}

void GameObject::update(float deltaTime)
{
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() == GameModeLevel && _b2Body != NULL)
    {
        setPosition( CCPointMake( _b2Body->GetPosition().x * PTM_RATIO, _b2Body->GetPosition().y * PTM_RATIO) );
        setRotation( -1 * CC_RADIANS_TO_DEGREES(_b2Body->GetAngle()) );
    }
}