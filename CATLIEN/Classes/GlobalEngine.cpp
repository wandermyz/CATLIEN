//
//  GlobalEngine.cpp
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#include "GlobalEngine.h"
#include "Input/GameInputManager.h"
#include "Input/LevelEditorInputManager.h"
USING_NS_CC;

static GlobalEngine _sharedGlobalEngine;

GlobalEngine::GlobalEngine():_levelEditorHandler(NULL), _inputManager(NULL), _physicsWorld(NULL)
{
    _gameMode = GameModeLevelEditor;
}

GlobalEngine::~GlobalEngine()
{
}

GlobalEngine* GlobalEngine::sharedGlobalEngine()
{
    return &_sharedGlobalEngine;
}

void GlobalEngine::switchToEditorMode()
{
    _gameMode = GameModeLevelEditor;
    switchInputManager(LevelEditorInputManager::create());
    CCLOG("Switched to Editor Mode");
}

void GlobalEngine::switchToGameMode()
{
    _gameMode = GameModeLevel;
    switchInputManager(GameInputManager::create());
    CCLOG("Switched to Game Mode");
}

void GlobalEngine::enterLevelMapLayer(LevelMapLayer *levelMapLayer)
{
    _levelMapLayer = levelMapLayer;
    _physicsWorld = PhysicsWorld::create();
    _physicsWorld->retain();
    
    switchToGameMode();
}

void GlobalEngine::leaveLevelMapLayer()
{
    _physicsWorld->release();
    _levelMapLayer = NULL;
    _gameMode = GameModeUnknown;
    switchInputManager(NULL);
}


void GlobalEngine::switchInputManager(InputManagerBase* newInputManager)
{
    if (newInputManager == _inputManager)
    {
        return;
    }
    
    if (_inputManager != NULL)
    {
        getLevelMapLayer()->removeChild(_inputManager, true);
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(_inputManager);
    }
    
    _inputManager = newInputManager;
    
    if (_inputManager != NULL)
    {
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(_inputManager, 0, true);
        getLevelMapLayer()->addChild(_inputManager, true);
    }
}



