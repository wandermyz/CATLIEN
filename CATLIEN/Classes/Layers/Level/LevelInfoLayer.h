//
//  LevelInfoLayer.h
//  CATLIEN
//
//  Created by Wander on 9/8/12.
//
//

#ifndef __CATLIEN__LevelInfoLayer__
#define __CATLIEN__LevelInfoLayer__

#include "cocos2d.h"

class LevelInfoLayer : public cocos2d::CCLayer
{
private:
    //cocos2d::CCMenuItemFont* _modeSwitchButton;
    void onModeSwitchButton(CCObject* source);
    
public:
    LAYER_CREATE_FUNC(LevelInfoLayer);
    bool init();
};

#endif /* defined(__CATLIEN__LevelInfoLayer__) */
