//
//  LevelMapLayer.h
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#ifndef __CATLIEN__LevelMapLayer__
#define __CATLIEN__LevelMapLayer__

#include "cocos2d.h"
#include "../../GameObjects/GameObject.h"

class LevelMapLayer : public cocos2d::CCLayer
{
private:
    
public:
    LAYER_CREATE_FUNC(LevelMapLayer);
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    //for editor
    void addElement(GameObject* gameObject);
    void setElementPosition(GameObject* gameObject, cocos2d::CCPoint position);
    void randomizeElementPosition(GameObject* gameObject);
};

#endif /* defined(__CATLIEN__LevelMapLayer__) */
