//
//  InputManagerBase.h
//  CATLIEN
//
//  Created by Wander on 9/3/12.
//
//

#ifndef __CATLIEN__InputManagerBase__
#define __CATLIEN__InputManagerBase__

#include "cocos2d.h"

#define INPUT_MANAGER_CREATE_FUNC(clz) \
static clz* create() \
{ \
clz *pRet = new clz(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
CC_SAFE_DELETE(pRet); \
pRet = NULL; \
return NULL; \
} \
}

class InputManagerBase : public cocos2d::CCNode, public cocos2d::CCTargetedTouchDelegate
{
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) = 0;
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) = 0;
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) = 0;
};

#endif /* defined(__CATLIEN__InputManagerBase__) */
