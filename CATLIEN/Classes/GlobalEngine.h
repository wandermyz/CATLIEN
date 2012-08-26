//
//  GlobalEngine.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#ifndef __CATLIEN__GlobalEngine__
#define __CATLIEN__GlobalEngine__

#include "LevelEditor/LevelEditorHandlerBase.h"

#ifndef NULL
#define NULL 0
#endif

class GlobalEngine
{
private:
    LevelEditorHandlerBase* _levelEditorHandler;
    
public:
    static GlobalEngine* sharedGlobalEngine();
    
    GlobalEngine();
    
    inline void setLevelEditorHandler(LevelEditorHandlerBase* handler)
    {
        _levelEditorHandler = handler;
    }
    
    inline LevelEditorHandlerBase* getLevelEditorHandler()
    {
        return _levelEditorHandler;
    }
};

#endif /* defined(__CATLIEN__GlobalEngine__) */
