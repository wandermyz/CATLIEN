//
//  GlobalEngine.cpp
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#include "GlobalEngine.h"

static GlobalEngine _sharedGlobalEngine;

GlobalEngine::GlobalEngine():_levelEditorHandler(NULL)
{
    
}

GlobalEngine* GlobalEngine::sharedGlobalEngine()
{
    return &_sharedGlobalEngine;
}
