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

LevelEditorInputManager* LevelEditorInputManager::create()
{
    LevelEditorInputManager* res = new LevelEditorInputManager();
    if (res && res->init())
    {
        res->autorelease();
        return res;
    }
    
    CC_SAFE_DELETE(res);
    return NULL;
}

bool LevelEditorInputManager::init()
{
    _manipulatingObject = NULL;
    return true;
}

bool LevelEditorInputManager::ccTouchBegan(CCTouch* touch, CCEvent* evnet)
{
    if (GlobalEngine::sharedGlobalEngine()->getGameMode() != GameModeLevelEditor)
    {
        return false;
    }
    
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
}

void LevelEditorInputManager::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    LevelMapLayer* levelMapLayer = GlobalEngine::sharedGlobalEngine()->getLevelMapLayer();
    
    if (_manipulatingObject != NULL)
    {
        GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->showEditorPanel(_manipulatingObject);
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
}



