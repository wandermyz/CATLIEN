//
//  LevelEditorLayer.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#ifndef __CATLIEN__LevelEditorLayer__
#define __CATLIEN__LevelEditorLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

#define LEVEL_EDITOR_LAYER_WIDTH 200

class LevelEditorLayer : public cocos2d::CCLayer
{
private:
    //cocos2d::extension::CCScrollView* creatingMenuContainer;
    cocos2d::CCMenu* creatingMenu;
    cocos2d::CCArray* creatingMenuItems;
    
    void buildCreatingMenu();
    
public:
    LAYER_CREATE_FUNC(LevelEditorLayer);
    virtual bool init();
    
    void creatingMenuItemCallback(cocos2d::CCObject* pSender);
};


#endif /* defined(__CATLIEN__LevelEditorLayer__) */
