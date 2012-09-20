//
//  Player.h
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#ifndef __CATLIEN__Player__
#define __CATLIEN__Player__

#include "cocos2d.h"
#include "GameObject.h"
#include "../Constants.h"

typedef enum
{
    PlayerMoveStateStop,
    PlayerMoveStateLeft,
    PlayerMoveStateRight
} PlayerMoveState;

typedef enum
{
    PlayerJumpStateNone,
    PlayerJumpStatePending, //Jump requested, but impulse is not applied yet
    PlayerJumpStateLeaving, //Impulse applied, but still grounded
    PlayerJumpStateOnAir   //Ungrounded
} PlayerJumpState;

class Player : public GameObject
{
protected:
    b2Fixture* _bodyFiexture;
    b2Fixture* _sensorFixture;
    
    PlayerMoveState _moveState;
    PlayerJumpState _jumpState;
    int _numFootContacts;
    
    GameObject* _currentGround;
    
    void addFootContact(GameObject* ground);
    void removeFootContact();
    
public:
    GAME_OBJECT_CREATE_FUNC(Player);
    GAME_OBJECT_TYPE_FUNC(GameObjectTypePlayer);
    virtual bool init();
    virtual void createB2Body();
    
    inline void setMoveState(PlayerMoveState moveState) {_moveState = moveState;}
    inline PlayerMoveState getMoveState() const {return _moveState;}
    
    inline void setJumpState(PlayerJumpState jumpState)
    {
        _jumpState = jumpState;
        cocos2d::CCLog("Jump State: %d", _jumpState);
    }
    inline PlayerJumpState getJumpState() const { return _jumpState;}
    
    inline bool isGrounded() {return _numFootContacts > 0;}
    
    void onBeginContact(b2Contact* contact); 
    void onEndContact(b2Contact* contact);
    
    inline GameObject* getCurrentGround() const {return _currentGround;}
};

#endif /* defined(__CATLIEN__Player__) */
