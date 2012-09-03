//
//  Planet.cpp
//  CATLIEN
//
//  Created by Wander on 8/19/12.
//
//

#include "Planet.h"
#include "../Physics/PhysicsWorld.h"
#include "../GlobalEngine.h"
USING_NS_CC;

bool Planet::init()
{
    if (!GameObject::init())
    {
        return false;
    }
    
    _radius = 0;
    _density = 1;
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
    resetB2Body();
}

void Planet::setDensity(float density)
{
    _density = density;
    resetB2Body();
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

void Planet::createB2Body()
{
    CCPoint p = getPosition();
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(p.x / PTM_RATIO, p.y / PTM_RATIO);
    
    _b2Body = GlobalEngine::sharedGlobalEngine()->getPhysicsWorld()->createBody(&bodyDef);
    
    b2CircleShape shape;
    shape.m_p.Set(0, 0);
    shape.m_radius = _radius / PTM_RATIO;
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = _density;
    fixtureDef.friction = 0.05f; //TODO: TBD
    _b2Body->CreateFixture(&fixtureDef);
}

float Planet::getB2Mass()
{
    return 4.1887902047863905 * pow(_radius / PTM_RATIO, 3) * _density;
}

