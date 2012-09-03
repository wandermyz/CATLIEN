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
#include "Layers/Level/LevelMapLayer.h"
#include "Input/InputManagerBase.cpp"

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
    InputManagerBase* _inputManager;
    
    void switchInputManager(InputManagerBase* inputManager);
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
    
    void enterLevelMapLayer(LevelMapLayer* levelMapLayer);
    void leaveLevelMapLayer();
    
    inline LevelMapLayer* getLevelMapLayer() const
    {
        return _levelMapLayer;
    }
    
    inline GameMode getGameMode() const
    {
        return _gameMode;
    }
    
    void switchToEditorMode();
    void switchToGameMode();
};

#endif /* defined(__CATLIEN__GlobalEngine__) */
