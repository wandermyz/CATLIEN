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

class Player : public GameObject
{
protected:
    b2Fixture* _bodyFiexture;
    b2Fixture* _sensorFixture;
    
    PlayerMoveState _moveState;
    int _numFootContacts;
    
    GameObject* _currentGround;
    
    //TODO: handle contact on multiple grounds
    inline void addFootContact(GameObject* ground)
    {
        _numFootContacts++;
        _currentGround = ground;
        if (_numFootContacts == 1)
        {
            CCLOG("Grounded");
        }
    }
    inline void removeFootContact()
    {
        _numFootContacts--;
        _currentGround = NULL;
        if (_numFootContacts == 0)
        {
            CCLOG("Ungrounded");
        }
        else if (_numFootContacts < 0)
        {
            CCLOGERROR("_numFootContacts goes negative in Player.h");
        }
    }
    
public:
    GAME_OBJECT_CREATE_FUNC(Player);
    GAME_OBJECT_TYPE_FUNC(GameObjectTypePlayer);
    virtual bool init();
    virtual void createB2Body();
    
    inline void setMoveState(PlayerMoveState moveState) {_moveState = moveState;}
    inline PlayerMoveState getMoveState() const {return _moveState;}
    
    inline bool isGrounded() {return _numFootContacts > 0;}
    
    void onBeginContact(b2Contact* contact); 
    void onEndContact(b2Contact* contact);
    
    inline GameObject* getCurrentGround() const {return _currentGround;}
};

#endif /* defined(__CATLIEN__Player__) */
