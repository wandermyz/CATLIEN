//
//  Player.cpp
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#include "Player.h"
#include "../GlobalEngine.h"
using namespace std;
USING_NS_CC;

bool Player::init()
{
    if (!GameObject::init())
    {
        return false;
    }
    setTexturePath("meow_1.png");
    setName("Player");
    
    return true;
}

void Player::createB2Body()
{
    CCPoint p = getPosition();
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p.x / PTM_RATIO, p.y / PTM_RATIO);
    
    _b2Body = GlobalEngine::sharedGlobalEngine()->getPhysicsWorld()->createBody(&bodyDef);
    
    b2PolygonShape shape;
    CCRect bb = boundingBox();
    shape.SetAsBox(bb.size.width / 2 / PTM_RATIO, bb.size.height / 2 / PTM_RATIO);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0;
    fixtureDef.friction = 1000; //TODO: TBD
    _b2Body->CreateFixture(&fixtureDef);
}

