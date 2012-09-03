//
//  GameInputManager.h
//  CATLIEN
//
//  Created by Wander on 9/2/12.
//
//

#ifndef __CATLIEN__GameInputManager__
#define __CATLIEN__GameInputManager__

#include "InputManagerBase.h"

typedef enum
{
    GameInputStateNone,
    GameInputStateHold,
    GameInputStateMoving,
} GameInputState;

class GameInputManager : public InputManagerBase
{
private:
    float _holdTime;
    GameInputState _state;

public:
    INPUT_MANAGER_CREATE_FUNC(GameInputManager);
    
    virtual bool init();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    virtual void onEnter();
    virtual void onExit();
    virtual void update(float deltaTime);

};

#endif /* defined(__CATLIEN__GameInputManager__) */
