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
#import "EditorPanelController.h"
#include "cocos2d.h"

@implementation LevelEditorManager
{
    UIView* _parentView;
    
    CreatingMenuController* _creatingMenuController;
    UIPopoverController* _creatingMenuPopover;
    
    EditorPanelController* _editorPanelController;
    UIPopoverController* _editorPanelPopover;
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
    _creatingMenuController = [[[CreatingMenuController alloc] init] retain];
    _creatingMenuPopover = [[[UIPopoverController alloc] initWithContentViewController:_creatingMenuController] retain];
    _creatingMenuPopover.delegate = self;
    
    [_creatingMenuPopover presentPopoverFromRect:CGRectMake(0, 0, 1, 1) inView:_parentView permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
    
}

-(void)hideCreatingMenu
{
    [_creatingMenuPopover dismissPopoverAnimated:YES];
}

-(void)showEditorPanelFor:(GameObject *)gameObject
{
    _editorPanelController = [[[EditorPanelController alloc] initWithGameObject:gameObject] retain];
    _editorPanelPopover = [[UIPopoverController alloc] initWithContentViewController:_editorPanelController];
    _editorPanelPopover.delegate = self;
    
    cocos2d::CCRect rect = gameObject->boundingBox();
    [_editorPanelPopover presentPopoverFromRect:CGRectMake(rect.origin.x, cocos2d::CCDirector::sharedDirector()->getWinSize().height - rect.origin.y - rect.size.height, rect.size.width, rect.size.height)
                                         inView:_parentView
                       permittedArrowDirections:UIPopoverArrowDirectionAny
                                       animated:YES];
}

-(void)hideEditorPanel
{
    [_editorPanelPopover dismissPopoverAnimated:YES];
}

-(void)popoverControllerDidDismissPopover:(UIPopoverController *)popoverController
{
    if (popoverController == _creatingMenuPopover)
    {
        [_creatingMenuController release];
    }
    if (popoverController == _editorPanelPopover)
    {
        [_editorPanelController release];
        
        //TODO
    }
    
    [popoverController release];
}

@end
