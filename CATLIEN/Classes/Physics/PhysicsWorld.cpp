//
//  PhysicsWorld.cpp
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#include "PhysicsWorld.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Planet.h"
#include "../GlobalEngine.h"

USING_NS_CC;

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


void PhysicsWorld::step(float deltaTime)
{
    //TODO:
    /*
     how to clear out friction? currently, no friction
     */
    Player* player = GlobalEngine::sharedGlobalEngine()->getPlayer();
    CCArray* planets = GlobalEngine::sharedGlobalEngine()->getLevelMapLayer()->getPlanets();
    
    //add gravity
    b2Vec2 force;
    force.SetZero();
    
    b2Body* playerBody = player->getB2Body();
    
    if (player->isGrounded() && player->getCurrentGround()->getType() == GameObjectTypePlanet)
    {
        //only apply gravity of current planet
        force = getGravity(player, (Planet*)player->getCurrentGround());
    }
    else
    {
        for (int i = 0; i < planets->count(); i++)
        {
            force += getGravity(player, (Planet*)planets->objectAtIndex(i));
        }
    }
    
    //rotate to gravity
    float angle = atan2(force.y, force.x) + b2_pi / 2.0f;
    playerBody->SetTransform(playerBody->GetPosition(), angle);
    
    playerBody->ApplyForceToCenter(force);
    
    //apply movement by force
    /*b2Vec2 localForce;
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
     */
    
    
    //apply movement by impulse
    if (player->isGrounded() && player->getJumpState() != PlayerJumpStateLeaving)
    {
        b2Vec2 localSpeed;
        switch (player->getMoveState()) {
            case PlayerMoveStateLeft:
                localSpeed.Set(-PLAYER_MOVE_SPEED, 0);
                break;
                
            case PlayerMoveStateRight:
                localSpeed.Set(PLAYER_MOVE_SPEED, 0);
                break;
                
            default:
                localSpeed.SetZero();
                break;
        }
        
        b2Rot rotation(angle);
        b2Vec2 globalSpeed = b2Mul(rotation, localSpeed);
        b2Vec2 impulse = globalSpeed - playerBody->GetLinearVelocity();
        impulse *= playerBody->GetMass();
        
        playerBody->ApplyLinearImpulse(impulse, playerBody->GetWorldCenter());
    }
    
    //apply jumping
    if (player->getJumpState() == PlayerJumpStatePending)
    {
        player->setJumpState(PlayerJumpStateLeaving);
        
        if (player->isGrounded())
        {
            b2Vec2 localJumpSpeed;
            localJumpSpeed.Set(PLAYER_JUMP_SPEED, 0);
            b2Rot jumpRotation(angle + b2_pi / 2.0f);
            b2Vec2 globalJumpSpeed = b2Mul(jumpRotation, localJumpSpeed);
            b2Vec2 jumpImpulse = globalJumpSpeed;
            jumpImpulse *= playerBody->GetMass();
            
            playerBody->ApplyLinearImpulse(jumpImpulse, playerBody->GetWorldCenter());
        }
    }
    
    //check damping
    if (player->isGrounded())
    {
        playerBody->SetLinearDamping(0);
    }
    else
    {
        playerBody->SetLinearDamping(PLAYER_DAMPING);
    }
    
    _world->Step(deltaTime, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

b2Vec2 PhysicsWorld::getGravity(Player *player, Planet *planet)
{
    b2Vec2 planetPos = planet->getB2Body()->GetPosition();
    
    b2Vec2 offset = planetPos - player->getB2Body()->GetPosition();
    float scalar = player->getB2Body()->GetMass() * planet->getB2Mass() / offset.LengthSquared() * GRAVITY_CONST;  //mass = 0 for static b2body, so use our own mass computing
    
    b2Vec2 gravity;
    gravity.Set(offset.x * scalar, offset.y * scalar);
    
    return gravity;
}
