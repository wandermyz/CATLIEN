//
//  LevelEditorHandler.mm
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#include "LevelEditorHandler.h"
#import "LevelEditorManager.h"

void LevelEditorHandler::showCreatingMenu()
{
    [[LevelEditorManager sharedLevelEditorManager] showCreatingMenu];
}

void LevelEditorHandler::hideCreatingMenu()
{
    [[LevelEditorManager sharedLevelEditorManager] hideCreatingMenu];
}

void LevelEditorHandler::showEditorPanel(GameObject *gameObject)
{
    [[LevelEditorManager sharedLevelEditorManager] showEditorPanelFor:gameObject];
}

void LevelEditorHandler::hideEditorPanel()
{
    [[LevelEditorManager sharedLevelEditorManager] hideEditorPanel];
}

