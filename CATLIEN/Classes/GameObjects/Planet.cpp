//
//  Planet.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "Planet.h"
USING_NS_CC;

bool Planet::init()
{
    if (!GameObject::init())
    {
        return false;
    }
    
    _radius = 0;
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

bool Planet::setTexturePath(const char *texturePath)
{
    if(GameObject::setTexturePath(texturePath))
    {
        _originalRadius = std::max(getContentSize().width, getContentSize().height) / 2;
        setRadius(_radius == 0 ? _originalRadius : _radius);
        return true;
    }
    else
    {
        return false;
    }
    
}

