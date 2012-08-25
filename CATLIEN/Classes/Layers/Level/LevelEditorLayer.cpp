//
//  LevelEditorLayer.cpp
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#include "LevelEditorLayer.h"
#include <string>
#include <vector>
USING_NS_CC;
using namespace std;


bool LevelEditorLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    setPosition(ccp(winSize.width - LEVEL_EDITOR_LAYER_WIDTH, 0));
    setContentSize(CCSizeMake(LEVEL_EDITOR_LAYER_WIDTH, winSize.height));
    
    buildCreatingMenu();
    creatingMenu->setPosition(ccp(LEVEL_EDITOR_LAYER_WIDTH / 2, winSize.height / 2));
        
    return true;
}

void LevelEditorLayer::buildCreatingMenu()
{
    string menuItemNames[] = {"Planet", "Platform", "MovingPlatform", "Tree", "NPC"};
    unsigned int menuItemCount = 5;
    
    creatingMenuItems = CCArray::createWithCapacity(menuItemCount);
    for (int i = 0; i < menuItemCount; i++)
    {
        creatingMenuItems->addObject(CCMenuItemFont::create(menuItemNames[i].c_str(), this, menu_selector(LevelEditorLayer::creatingMenuItemCallback)));
    }
        
    creatingMenu = CCMenu::createWithArray(creatingMenuItems);
    creatingMenu->alignItemsVertically();
    
    addChild(creatingMenu);
}

void LevelEditorLayer::creatingMenuItemCallback(CCObject *pSender)
{
    CCLOG("item selected");
}

