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

#define PLAYER_MOVE_SPEED 4.0f

typedef enum
{
    PlayerMoveStateStop,
    PlayerMoveStateLeft,
    PlayerMoveStateRight
} PlayerMoveState;

class Player : public GameObject
{
protected:
    PlayerMoveState _moveState;
    
public:
    GAME_OBJECT_CREATE_FUNC(Player);
    GAME_OBJECT_TYPE_FUNC(GameObjectTypePlayer);
    virtual bool init();
    virtual void createB2Body();
    
    inline void setMoveState(PlayerMoveState moveState) {_moveState = moveState;}
    inline PlayerMoveState getMoveState() const {return _moveState;}
};

#endif /* defined(__CATLIEN__Player__) */
