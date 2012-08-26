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

class LevelMapLayer : public cocos2d::CCLayer
{
private:
    cocos2d::CCArray* mapElements;
    
public:
    LAYER_CREATE_FUNC(LevelMapLayer);
    
    virtual bool init();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
};

#endif /* defined(__CATLIEN__LevelMapLayer__) */
