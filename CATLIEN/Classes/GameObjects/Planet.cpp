//
//  Planet.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "Planet.h"
#include "../Graphics/AnimationTexture.h"
using namespace std;
USING_NS_CC;

bool Planet::init()
{
    if (!GameObject::init())
    {
        return false;
    }
    
    setTexturePath("planet_1.png");
    setFrameCount(0);
    
    return true;
}

bool Planet::containsPoint(const cocos2d::CCPoint &p)
{
    return ccpDistanceSQ(p, getPosition()) < _radius * _radius;
}

void Planet::drawSelection()
{
    ccDrawColor4B(255, 255, 255, 255);
    glLineWidth(3);
    
    ccDrawCircle(getPosition(), _radius, CC_DEGREES_TO_RADIANS(360), 50, false);
}

void Planet::setRadius(float radius)
{
    _radius = radius;
    setScale(_radius / _originalRadius);
}

void Planet::setDensity(float density)
{
    _density = density;
}

void Planet::setTexturePath(const char *texturePath)
{
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
    
    _originalRadius = std::max(getContentSize().width, getContentSize().height) / 2;
    setRadius(_originalRadius);
}

void Planet::setFrameCount(int frameCount)
{
    _frameCount = frameCount;
}