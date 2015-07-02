//
//  EditorPanelControllerViewController.m
//  CATLIEN
//
//  Created by Wander on 8/28/12.
//
//

#import "EditorPanelController.h"
#import "TextFieldTableViewCell.h"
#import "PlanetContentViewController.h"
#import "../../Classes/GlobalEngine.h"

@interface EditorPanelController ()

@end

@implementation EditorPanelController
{
    GameObject* _gameObject;
    UIButton* _deleteButton;
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
    if (_deleteButton)
    {
        [_deleteButton release];
    }
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
            cell = [[[TextFieldTableViewCell alloc] initWithDelegate:self reuseIdentifier:[CellIdentifiers objectAtIndex:indexPath.section]] autorelease];
        }
        
        ((TextFieldTableViewCell*)cell).textField.text = [NSString stringWithUTF8String:_gameObject->getName().c_str()];
        ((TextFieldTableViewCell*)cell).label = @"Name";
        
    }
    else if (indexPath.section == 1)
    {
        if (cell == nil) {
            cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[CellIdentifiers objectAtIndex:indexPath.section]] autorelease];
            
            switch (_gameObject->getType())
            {
                case GameObjectTypePlanet:
                {
                    PlanetContentViewController* subview = [[PlanetContentViewController alloc] initWithPlanet:(Planet *)_gameObject];
                    [cell addSubview:subview.view];
                    break;
                }
                    
                default:
                {
                    break;
                }
            }
        }
    }

    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 1)
    {
        NSInteger rowNum;
        
        switch (_gameObject->getType())
        {
            case GameObjectTypePlanet:
                rowNum = 4;
                break;
                
            default:
                rowNum = 10;
                break;
        }
        
        return 60 * rowNum;
    }
    else
    {
        return 60;
    }
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

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    if (section == 1)
    {
        if (_deleteButton == nil)
        {
            _deleteButton = [[UIButton buttonWithType:UIButtonTypeRoundedRect] retain];
            [_deleteButton setTitle:@"Delete" forState:UIControlStateNormal];
            _deleteButton.backgroundColor = [UIColor clearColor];
            [_deleteButton addTarget:self action:@selector(onDeleteButtonClick:) forControlEvents:UIControlEventTouchUpInside];
        }
        
        return _deleteButton;
    }
    else
    {
        return nil;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    if (section == 1)
    {
        return 45.0;
    }
    else
    {
        return 0;
    }
}

- (void)onDeleteButtonClick:(id)sender
{
    GlobalEngine::sharedGlobalEngine()->getLevelMapLayer()->removeElement(_gameObject);
    GlobalEngine::sharedGlobalEngine()->getLevelEditorHandler()->hideEditorPanel();
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
