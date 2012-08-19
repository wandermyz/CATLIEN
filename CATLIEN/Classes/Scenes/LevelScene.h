//
//  LevelScene.h
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//
//

#ifndef __CATLIEN__LevelScene__
#define __CATLIEN__LevelScene__

#include "cocos2d.h"

class LevelScene : public cocos2d::CCScene {

public:
    virtual bool init();
    virtual void end();
    SCENE_NODE_FUNC(LevelScene);

};

#endif /* defined(__CATLIEN__LevelScene__) */
