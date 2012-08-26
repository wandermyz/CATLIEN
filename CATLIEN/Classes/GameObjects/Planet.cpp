//
//  Planet.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "Planet.h"
#include "../Graphics/AnimationTexture.h"

USING_NS_CC;

bool Planet::init()
{
    if (!GameObject::init())
    {
        return false;
    }
    
    _texturePath = "planet_1.png";
    _frameCount = 0;
    
    _texture = AnimationTexture::createWithSpriteFrameName(_texturePath.c_str());
    
    if (_texture == NULL)
    {
        return false;
    }
    
    addChild(_texture);
    _texture->setAnchorPoint(ccp(0,0));
    
    setContentSize(_texture->getContentSize());
    setAnchorPoint(ccp(0.5, 0.5));
    
    _radius = std::max(getContentSize().width, getContentSize().height) / 2;
    
    return true;
}

bool Planet::containsPoint(const cocos2d::CCPoint &p)
{
    return ccpDistanceSQ(p, getPosition()) < _radius * _radius;
}

