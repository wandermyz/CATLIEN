//
//  LevelEditorHandler.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#ifndef __CATLIEN__LevelEditorHandler__
#define __CATLIEN__LevelEditorHandler__

#include "LevelEditorHandlerBase.h"

class LevelEditorHandler : public LevelEditorHandlerBase
{
public:
    virtual void showCreatingMenu();
    virtual void hideCreatingMenu();
};

#endif /* defined(__CATLIEN__LevelEditorHandler__) */
