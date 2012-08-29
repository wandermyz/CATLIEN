//
//  LevelEditorManager.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#import <Foundation/Foundation.h>
#include "../../Classes/GameObjects/GameObject.h"

@class AppController;

@interface LevelEditorManager : NSObject <UIPopoverControllerDelegate>
+(LevelEditorManager*) sharedLevelEditorManager;
+(void) initSharedWithParentView:(UIView*)parentView;
-(LevelEditorManager*) initWithParentView:(UIView*)parentView;
-(void) showCreatingMenu;
-(void) hideCreatingMenu;
-(void) showEditorPanelFor: (GameObject*)gameObject;
-(void) hideEditorPanel;
@end
