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
#include "Input/LevelEditorInputManager.h"
#include "Layers/Level/LevelMapLayer.h"

#ifndef NULL
#define NULL 0
#endif

typedef enum
{
    GameModeUnknown,
    GameModeLevel,
    GameModeLevelEditor
} GameMode;

class GlobalEngine
{
private:
    LevelEditorHandlerBase* _levelEditorHandler;
    LevelMapLayer* _levelMapLayer;
    GameMode _gameMode;
    LevelEditorInputManager* _levelEditorInputManager;
    
public:
    static GlobalEngine* sharedGlobalEngine();
    
    GlobalEngine();
    virtual ~GlobalEngine();
    
    inline void setLevelEditorHandler(LevelEditorHandlerBase* handler)
    {
        _levelEditorHandler = handler;
    }
    
    inline LevelEditorHandlerBase* getLevelEditorHandler() const
    {
        return _levelEditorHandler;
    }
    
    inline void setLevelMapLayer(LevelMapLayer* levelMapLayer)
    {
        _levelMapLayer = levelMapLayer;
    }
    
    inline LevelMapLayer* getLevelMapLayer() const
    {
        return _levelMapLayer;
    }
    
    inline GameMode getGameMode() const
    {
        return _gameMode;
    }
    
    LevelEditorInputManager* getLevelEditorInputManager();
};

#endif /* defined(__CATLIEN__GlobalEngine__) */
