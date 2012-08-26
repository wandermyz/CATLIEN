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