//
//  LevelEditorManager.h
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#import <Foundation/Foundation.h>

@class AppController;

@interface LevelEditorManager : NSObject <UIPopoverControllerDelegate>
+(LevelEditorManager*) sharedLevelEditorManager;
+(void) initSharedWithParentView:(UIView*)parentView;
-(LevelEditorManager*) initWithParentView:(UIView*)parentView;
-(void) showCreatingMenu;
-(void) hideCreatingMenu;
@end
