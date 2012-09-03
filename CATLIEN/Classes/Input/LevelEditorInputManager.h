//
//  LevelEditorInputManager.h
//  CATLIEN
//
//  Created by Wander on 8/26/12.
//
//

#ifndef __CATLIEN__LevelEditorInputManager__
#define __CATLIEN__LevelEditorInputManager__

#include "InputManagerBase.h"
#include "../GameObjects/GameObject.h"

typedef enum
{
    LevelEditorInputStateNone,
    LevelEditorInputStateHold,
    LevelEditorInputStateMoving,
} LevelEditorInputState;

class LevelEditorInputManager : public InputManagerBase
{
private:
    GameObject* _manipulatingObject;
    LevelEditorInputState _state;
    float _holdTime;
    
public:
    INPUT_MANAGER_CREATE_FUNC(LevelEditorInputManager);
    
    virtual bool init();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    virtual void onEnter();
    virtual void onExit();
    virtual void update(float deltaTime);

};

#endif /* defined(__CATLIEN__LevelEditorInputManager__) */
