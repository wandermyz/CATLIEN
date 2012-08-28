//
//  GlobalEngine.cpp
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#include "GlobalEngine.h"
USING_NS_CC;

static GlobalEngine _sharedGlobalEngine;

GlobalEngine::GlobalEngine():_levelEditorHandler(NULL), _levelEditorInputManager(NULL)
{
    _gameMode = GameModeLevelEditor;
}

GlobalEngine::~GlobalEngine()
{
    _levelEditorInputManager->release();
}

GlobalEngine* GlobalEngine::sharedGlobalEngine()
{
    return &_sharedGlobalEngine;
}

LevelEditorInputManager* GlobalEngine::getLevelEditorInputManager()
{
    if (_levelEditorInputManager == NULL)
    {
        _levelEditorInputManager = LevelEditorInputManager::create();
        _levelEditorInputManager->retain();
    }
    
    return _levelEditorInputManager;
}
