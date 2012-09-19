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
    _moveState = PlayerMoveStateStop;
    _numFootContacts = 0;
    _bodyFiexture = NULL;
    _sensorFixture = NULL;
    return true;
}

void Player::createB2Body()
{
    CCPoint p = getPosition();
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p.x / PTM_RATIO, p.y / PTM_RATIO);
    bodyDef.fixedRotation = true;
    
    _b2Body = GlobalEngine::sharedGlobalEngine()->getPhysicsWorld()->createBody(&bodyDef);
    
    b2PolygonShape shape;
    CCRect bb = boundingBox();
    shape.SetAsBox(bb.size.width / 2 / PTM_RATIO, bb.size.height / 2 / PTM_RATIO);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0;
    fixtureDef.friction = PLAYER_FRICTION;
    _bodyFiexture = _b2Body->CreateFixture(&fixtureDef);
    _bodyFiexture->SetUserData(this);
    
    
    _b2Body->SetLinearDamping(PLAYER_DAMPING);
    
    //add foot sensor fixture
    b2PolygonShape sensorShape;
    sensorShape.SetAsBox(0.3, 0.3, b2Vec2(0, -bb.size.height / 2 / PTM_RATIO), 0);
    b2FixtureDef sensorFixtureDef;
    fixtureDef.shape = &sensorShape;
    fixtureDef.isSensor = true;
    _sensorFixture = _b2Body->CreateFixture(&fixtureDef);
    _sensorFixture->SetUserData(this);
}

void Player::onBeginContact(b2Contact *contact)
{
    if (contact->GetFixtureA() == _sensorFixture)
    {
        addFootContact();
    }
    
    if (contact->GetFixtureB() == _sensorFixture)
    {
        addFootContact();
    }
}

void Player::onEndContact(b2Contact *contact)
{
    if (contact->GetFixtureA() == _sensorFixture)
    {
        removeFootContact();
    }
    
    if (contact->GetFixtureB() == _sensorFixture)
    {
        removeFootContact();
    }
    
}

