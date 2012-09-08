//
//  LevelEditorInputManager.cpp
//  CATLIEN
//
//  Created by Wander on 8/26/12.
//
//

#include "LevelEditorInputManager.h"
#include "../GlobalEngine.h"

USING_NS_CC;

#define EXIT_EDITOR_HOLD_TIME 1.0f

bool LevelEditorInputManager::init()
{
    _manipulatingObject = NULL;
    _holdTime = 0;
    _state = LevelEditorInputStateNone;
    return true;
}

bool LevelEditorInputManager::ccTouchBegan(CCTouch* touch, CCEvent* evnet)
{
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() != GameModeLevelEditor)
    {
        CCLOGERROR("LevelEditorInputManager triggered in game mode %d", GlobalEngine::sharedGlobalEngine()->getGameMode());
        return false;
    }
    
    _state = LevelEditorInputStateHold;
    _holdTime = 0;
    
    LevelMapLayer* levelMapLayer = GlobalEngine::sharedGlobalEngine()->getLevelMapLayer();
    
    //find game object that the touch hits
    //TODO: K-D Tree?
    CCArray* elements = levelMapLayer->getGameObjects();
    for (int i = elements->count() - 1; i >= 0; i--)
    {
        GameObject* gameObject = (GameObject*)(elements->data->arr[i]);
        if (gameObject != NULL)
        {
            if (gameObject->containsPoint(touch->getLocation()))
            {
                _manipulatingObject = gameObject;
                levelMapLayer->deselectAll();
                levelMapLayer->selectElement(gameObject);
                return true;
            }
        }
    }
    
    
    return true;
}

void LevelEditorInputManager::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if (_manipulatingObject != NULL)
    {
         _manipulatingObject->setPosition(ccpAdd(_manipulatingObject->getPosition(), touch->getDelta()));
    }
    _state = LevelEditorInputStateMoving;
}

void LevelEditorInputManager::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    LevelMapLayer* levelMapLayer = GlobalEngine::sharedGlobalEngine()->getLevelMapLayer();
    
    if (_state == LevelEditorInputStateHold && _holdTime > EXIT_EDITOR_HOLD_TIME)
    {
        //use toggle button instead
        //GlobalEngine::sharedGlobalEngine()->switchToGameMode();
    }
    else if (_manipulatingObject != NULL)
    {
        if (_state == LevelEditorInputStateHold)
        {
            GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showEditorPanel(_manipulatingObject);
        }
        else if (_state == LevelEditorInputStateMoving)
        {
            _manipulatingObject->resetB2Body();
        }
        
        _manipulatingObject = NULL;
    }
    else if (levelMapLayer->getSelections()->count() > 0)
    {
        levelMapLayer->deselectAll();
    }
    else
    {
        GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showCreatingMenu();
    }
    
    _state = LevelEditorInputStateNone;
}

void LevelEditorInputManager::onEnter()
{
    CCNode::onEnter();
    scheduleUpdate();
}

void LevelEditorInputManager::onExit()
{
    unscheduleUpdate();
    CCNode::onExit();
}

void LevelEditorInputManager::update(float deltaTime)
{
    if (_state == LevelEditorInputStateHold)
    {
        _holdTime += deltaTime;
    }
}


