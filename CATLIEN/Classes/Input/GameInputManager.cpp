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
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint pos = touch->getLocation();
    
    if (pos.y < winSize.height / 2)
    {
        if (pos.x < winSize.width / 3)
        {
            GlobalEngine::sharedGlobalEngine()->getPlayer()->setMoveState(PlayerMoveStateLeft);
            CCLog("Move Left");
        }
        else if (pos.x > winSize.width * 2/3)
        {
            GlobalEngine::sharedGlobalEngine()->getPlayer()->setMoveState(PlayerMoveStateRight);
            CCLog("Move Right");
        }
    }
    
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
        //use toggle button instead
        /*
        if (touch->getLocation().x < 100 && touch->getLocation().y > CCDirector::sharedDirector()->getWinSize().height - 100)
        {
            GlobalEngine::sharedGlobalEngine()->switchToEditorMode();
            GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showCreatingMenu();
            return;
        }*/
    }
    
    if (GlobalEngine::sharedGlobalEngine()->getPlayer()->getMoveState() != PlayerMoveStateStop)
    {
        GlobalEngine::sharedGlobalEngine()->getPlayer()->setMoveState(PlayerMoveStateStop);
        CCLog("Move Stop");
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