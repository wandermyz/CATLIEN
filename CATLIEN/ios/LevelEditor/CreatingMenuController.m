//
//  CreatingMenuController.m
//  CATLIEN
//
//  Created by Wander on 8/25/12.
//
//

#import "CreatingMenuController.h"
#import "LevelEditorManager.h"

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
    menuItemNames = [[[NSArray alloc] initWithObjects:
              @"Planet",@"Platform",
              @"MovingPlatform",
              @"Tree",
              @"NPC",
              nil] autorelease];
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
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

- (UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *CellIdentifier = @"CreatingMenuCell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier ] autorelease];
    }
    
    // Set up the cell...
    NSString *cellValue = [menuItemNames objectAtIndex:indexPath.row];
    cell.textLabel.text = cellValue;
    cell.textLabel.textAlignment = UITextAlignmentCenter;
    
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
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
        
    [[LevelEditorManager sharedLevelEditorManager] hideCreatingMenu];
}


@end
