//
//  LevelInfoLayer.cpp
//  CATLIEN
//
//  Created by Wander on 9/8/12.
//
//

#include "LevelInfoLayer.h"
#include "../../GlobalEngine.h"
USING_NS_CC;

bool LevelInfoLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    //put mode switch button
    CCMenuItemFont::setFontSize(18);
    //modeSwitchButton = CCMenuItemFont::create("Edit Mode", this, menu_selector(LevelInfoLayer::onModeSwitchButton));
    
    CCMenuItemFont* editorModeItem = CCMenuItemFont::create("Editor Mode");
    CCMenuItemFont* gameModeItem = CCMenuItemFont::create("Game Mode");
    CCMenuItemToggle* modeToggle = CCMenuItemToggle::createWithTarget(this, menu_selector(LevelInfoLayer::onModeSwitchButton), editorModeItem, gameModeItem, NULL);
    
    CCMenu* menu = CCMenu::createWithItem(modeToggle);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    menu->setPosition(ccp(60, winSize.height - 40));
    
    addChild(menu);
    
    return true;
}

void LevelInfoLayer::onModeSwitchButton(CCObject *source)
{
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() == GameModeLevelEditor)
    {
        GlobalEngine::sharedGlobalEngine()->switchToGameMode();
    }
    else if (GlobalEngine::sharedGlobalEngine()->getGameMode() == GameModeLevel)
    {
        GlobalEngine::sharedGlobalEngine()->switchToEditorMode();
    }
}