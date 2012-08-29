//
//  LevelEditorHandlerBase.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#ifndef __CATLIEN__LevelEditorHandlerBase__
#define __CATLIEN__LevelEditorHandlerBase__

#include "../GameObjects/GameObject.h"

class LevelEditorHandlerBase
{
public:
    virtual void showCreatingMenu() = 0;
    virtual void hideCreatingMenu() = 0;
    virtual void showEditorPanel(GameObject* gameObject) = 0;
    virtual void hideEditorPanel() = 0;
};

#endif /* defined(__CATLIEN__LevelEditorHandlerBase__) */
