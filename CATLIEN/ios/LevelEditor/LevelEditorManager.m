//
//  LevelEditorManager.m
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#import "LevelEditorManager.h"
#import "AppController.h"
#import "CreatingMenuController.h"

@implementation LevelEditorManager
{
    UIView* _parentView;
    CreatingMenuController* _creatingMenuController;
    UIPopoverController* _creatingMenuPopover;
}

static LevelEditorManager* _sharedLevelEditorManager = nil;

+(LevelEditorManager*) sharedLevelEditorManager
{
    NSAssert(_sharedLevelEditorManager != nil, @"LevelEditorManager not initialized.");
    return _sharedLevelEditorManager;
}

+(void)initSharedWithParentView:(UIView *)parentView
{
    _sharedLevelEditorManager = [[LevelEditorManager alloc] initWithParentView:parentView];
}

-(LevelEditorManager *)initWithParentView:(UIView *)parentView
{
    self = [super init];
    if (!self)
    {
        return nil;
    }
    
    _parentView = parentView;
    
    return self;
}

-(void)showCreatingMenu
{
    _creatingMenuController = [[[CreatingMenuController alloc] init] autorelease];
    _creatingMenuPopover = [[UIPopoverController alloc] initWithContentViewController:_creatingMenuController];
    //_creatingMenuPopover.delegate = self;
    
    [_creatingMenuPopover presentPopoverFromRect:CGRectMake(0, 0, 1, 1) inView:_parentView permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
    
}

-(void)hideCreatingMenu
{
    [_creatingMenuPopover dismissPopoverAnimated:YES];
}

-(void)popoverControllerDidDismissPopover:(UIPopoverController *)popoverController
{
    [_creatingMenuPopover release];
}

@end
