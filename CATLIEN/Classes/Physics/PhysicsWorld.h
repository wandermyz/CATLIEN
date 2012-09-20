//
//  PhysicsWorld.h
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#ifndef __CATLIEN__PhysicsWorld__
#define __CATLIEN__PhysicsWorld__

#include "cocos2d.h"
#include "Box2D.h"
#include "../GameObjects/Planet.h"
#include "../GameObjects/Player.h"

#define PTM_RATIO 32
#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 1

class PhysicsWorld : public cocos2d::CCNode, public b2ContactListener
{
private:
    b2World* _world;
    b2Vec2 getGravity(Player* player, Planet* planet);
    
public:
    static PhysicsWorld* create()
    {
        PhysicsWorld* pRet = new PhysicsWorld();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
    
    inline b2World* getB2World() const {return _world;}
    
    bool init();
    virtual ~PhysicsWorld();
    
    void step(float deltaTime);
    b2Body* createBody(const b2BodyDef* bodyDef);
    void destroyBody(b2Body* body);
    void playerJump();
    
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
};

#endif /* defined(__CATLIEN__PhysicsWorld__) */
