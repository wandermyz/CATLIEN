//
//  LevelEditorInputManager.h
//  CATLIEN
//
//  Created by Wander on 8/26/12.
//
//

#ifndef __CATLIEN__LevelEditorInputManager__
#define __CATLIEN__LevelEditorInputManager__

#include "cocos2d.h"
#include "../GameObjects/GameObject.h"

class LevelEditorInputManager : public cocos2d::CCNode, public cocos2d::CCTargetedTouchDelegate
{
private:
    
    GameObject* _manipulatingObject;
    
public:
    static LevelEditorInputManager* create();
    
    virtual bool init();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
};

#endif /* defined(__CATLIEN__LevelEditorInputManager__) */
