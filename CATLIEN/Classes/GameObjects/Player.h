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

class Player : public GameObject, public b2ContactListener
{
protected:
    PlayerMoveState _moveState;
    int _numFootContacts;
        
public:
    static const int fixtureTagBody;
    static const int fixtureTagSensor;
    
    GAME_OBJECT_CREATE_FUNC(Player);
    GAME_OBJECT_TYPE_FUNC(GameObjectTypePlayer);
    virtual bool init();
    virtual void createB2Body();
    
    inline void setMoveState(PlayerMoveState moveState) {_moveState = moveState;}
    inline PlayerMoveState getMoveState() const {return _moveState;}
    
    //TODO: support multiple ground types
    inline void addFootContact()
    {
        _numFootContacts++;
        if (_numFootContacts == 1)
        {
            CCLOG("Grounded");
        }
    } 
    inline void removeFootContact()
    {
        _numFootContacts--;
        if (_numFootContacts == 0)
        {
            CCLOG("Ungrounded");
        }
        else if (_numFootContacts < 0)
        {
            CCLOGERROR("_numFootContacts goes negative in Player.h");
        }
    }
    inline bool isGrounded() {return _numFootContacts > 0;}
};

#endif /* defined(__CATLIEN__Player__) */
