//
//  PhysicsWorld.cpp
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#include "PhysicsWorld.h"
#include "../GameObjects/Player.h"
#include "../GlobalEngine.h"

bool PhysicsWorld::init()
{
    b2Vec2 gravity;
    gravity.Set(0, 0);
    _world = new b2World(gravity);
    _world->SetAllowSleeping(true);
    _world->SetContinuousPhysics(true);
    _world->SetContactListener(this);
    
    return true;
}

PhysicsWorld::~PhysicsWorld()
{
    delete _world;
}

void PhysicsWorld::step(float deltaTime)
{
    _world->Step(deltaTime, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

b2Body* PhysicsWorld::createBody(const b2BodyDef* bodyDef)
{
    return _world->CreateBody(bodyDef);
}

void PhysicsWorld::destroyBody(b2Body *body)
{
    _world->DestroyBody(body);
}

void PhysicsWorld::BeginContact(b2Contact *contact)
{    
    void* dataA = contact->GetFixtureA()->GetUserData();
    void* dataB = contact->GetFixtureB()->GetUserData();
    
    GameObjectType typeA = dataA == NULL ? GameObjectTypeNone : ((GameObject*)dataA)->getType();
    GameObjectType typeB = dataB == NULL ? GameObjectTypeNone : ((GameObject*)dataB)->getType();
    
    if (typeA == GameObjectTypePlayer || typeB == GameObjectTypePlayer)
    {
        GlobalEngine::sharedGlobalEngine()->getPlayer()->onBeginContact(contact);
    }
}

void PhysicsWorld::EndContact(b2Contact *contact)
{
    void* dataA = contact->GetFixtureA()->GetUserData();
    void* dataB = contact->GetFixtureB()->GetUserData();
    
    GameObjectType typeA = dataA == NULL ? GameObjectTypeNone : ((GameObject*)dataA)->getType();
    GameObjectType typeB = dataB == NULL ? GameObjectTypeNone : ((GameObject*)dataB)->getType();
    
    if (typeA == GameObjectTypePlayer || typeB == GameObjectTypePlayer)
    {
        GlobalEngine::sharedGlobalEngine()->getPlayer()->onEndContact(contact);
    }
}