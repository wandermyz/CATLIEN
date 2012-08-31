//
//  EditorPanelControllerViewController.m
//  CATLIEN
//
//  Created by Wander on 8/28/12.
//
//

#import "EditorPanelController.h"
#import "TextFieldTableViewCell.h"

@interface EditorPanelController ()

@end

@implementation EditorPanelController
{
    GameObject* _gameObject;
}

- (id)initWithGameObject:(GameObject *)gameObject
{
    self = [super init];
    
    if (self)
    {
        _gameObject = gameObject;
    }
    
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
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

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{   
    NSArray *CellIdentifiers = [NSArray arrayWithObjects:@"TextField", @"EditorContent", nil];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:[CellIdentifiers objectAtIndex:indexPath.section]];
    
    if (indexPath.section == 0)
    {
        if (cell == nil) {
            cell = [[[TextFieldTableViewCell alloc] initWithLabel:@"Name" reuseIdentifier:[CellIdentifiers objectAtIndex:indexPath.section] delegate:self] autorelease];
            [(TextFieldTableViewCell*)cell setTextFieldValue:[NSString stringWithUTF8String:_gameObject->getName().c_str()]];
        }
        
    }
    else if (indexPath.section == 1)
    {
        if (cell == nil) {
            cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[CellIdentifiers objectAtIndex:indexPath.section]] autorelease];
        }
    }

    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    if (section == 0)
    {
        return @"Basic";
    }
    else if (section == 1)
    {
        return @"Object";
    }
    
    return nil;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    _gameObject->setName([textField.text UTF8String]);
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
