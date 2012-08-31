//
//  CreatingMenuController.m
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#import "CreatingMenuController.h"
#import "LevelEditorManager.h"

#include "../../Classes/GameObjects/GameObjects.h"
#include "../../Classes/GlobalEngine.h"

@interface CreatingMenuController ()

@end

@implementation CreatingMenuController
{
    NSArray* menuItemNames;
}


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
 
    [self createMenuItems];
    
    return self;
}

- (void)createMenuItems
{
    menuItemNames = [[NSArray alloc] initWithObjects:
              @"Planet",
              @"Platform",
              @"MovingPlatform",
              @"Tree",
              @"NPC",
              nil];
    [menuItemNames retain];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    [menuItemNames release];
    menuItemNames = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

- (UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier ] autorelease];
    }
    
    // Set up the cell...
    NSString *cellValue = [menuItemNames objectAtIndex:indexPath.row];
    cell.textLabel.text = cellValue;

    return cell;
}

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return menuItemNames.count;
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    GameObject* gameObject;
    
    switch (indexPath.row) {
        case 0:
            gameObject = Planet::create();
            break;
            
        default:
            gameObject = NULL;
            break;
    }
    
    if (gameObject != NULL)
    {
        GlobalEngine::sharedGlobalEngine()->getLevelMapLayer()->addElement(gameObject);
        GlobalEngine::sharedGlobalEngine()->getLevelMapLayer()->randomizeElementPosition(gameObject);
    }
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    [[LevelEditorManager sharedLevelEditorManager] hideCreatingMenu];
}


@end
