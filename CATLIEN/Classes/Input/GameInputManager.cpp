//
//  GameInputManager.cpp
//  CATLIEN
//
//  Created by Wander on 9/2/12.
//
//

#include "GameInputManager.h"
#include "../GlobalEngine.h"

USING_NS_CC;

#define ENTER_EDITOR_HOLD_TIME 1.0f

bool GameInputManager::init()
{
    _holdTime = 0;
    _state = GameInputStateNone;
    return true;
}

bool GameInputManager::ccTouchBegan(CCTouch* touch, CCEvent* evnet)
{
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() != GameModeLevel)
    {
        CCLOGERROR("GameInputManager triggered in game mode %d", GlobalEngine::sharedGlobalEngine()->getGameMode());
        return false;
    }
    
    _holdTime = 0;
    _state = GameInputStateHold;
    
    return true;
}

void GameInputManager::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    _state = GameInputStateMoving;
}

void GameInputManager::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if (_state == GameInputStateHold && _holdTime > ENTER_EDITOR_HOLD_TIME)
    {
        if (touch->getLocation().x < 100 && touch->getLocation().y > CCDirector::sharedDirector()->getWinSize().height - 100)
        {
            GlobalEngine::sharedGlobalEngine()->switchToEditorMode();
            GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showCreatingMenu();
        }
    }
}

void GameInputManager::onEnter()
{
    CCNode::onEnter();
    scheduleUpdate();
}

void GameInputManager::onExit()
{
    unscheduleUpdate();
    CCNode::onExit();
}

void GameInputManager::update(float deltaTime)
{
    if (_state == GameInputStateHold)
    {
        _holdTime += deltaTime;
    }
}