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
#include "LevelEditorLayer.h"

class LevelMapLayer : public cocos2d::CCLayer
{
private:
    cocos2d::CCArray* mapElements;
    LevelEditorLayer* editorLayer;
    
public:
    LAYER_CREATE_FUNC(LevelMapLayer);
    
    virtual bool init();
};

#endif /* defined(__CATLIEN__LevelMapLayer__) */
