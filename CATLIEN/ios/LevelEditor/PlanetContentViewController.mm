//
//  PlanetContentViewController.m
//  CATLIEN
//
//  Created by Wander on 8/31/12.
//
//

#import "PlanetContentViewController.h"
#import "TextFieldTableViewCell.h"

@interface PlanetContentViewController ()

@end

@implementation PlanetContentViewController
{
    Planet* _planet;
}

#define PLANET_ROW_TEXTURE 0
#define PLANET_ROW_FRAME_COUNT 1
#define PLANET_ROW_RADIUS 2
#define PLANET_ROW_DENSITY 3

- (id)initWithPlanet:(Planet *)planet
{
    self = [super init];
    if (self) {
        _planet = planet;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell;
    
    switch (indexPath.row)
    {
        case PLANET_ROW_TEXTURE:
        case PLANET_ROW_FRAME_COUNT:
            cell = [tableView dequeueReusableCellWithIdentifier:@"TextField"];
            if (!cell)
            {
                cell = [[[TextFieldTableViewCell alloc] initWithDelegate:self reuseIdentifier:@"TextField"] autorelease];
            }
            break;
            
        case PLANET_ROW_RADIUS:
        case PLANET_ROW_DENSITY:
            cell = [tableView dequeueReusableCellWithIdentifier:@"Slider"];
            if (!cell)
            {
                cell = [[[UITableViewCell alloc] init] autorelease];
            }
            break;
    }
    
    switch (indexPath.row)
    {
        case PLANET_ROW_TEXTURE:
            [(TextFieldTableViewCell*)cell setLabel:@"Texture"];
            break;
            
        case PLANET_ROW_FRAME_COUNT:
            [(TextFieldTableViewCell*)cell setLabel:@"Frames"];
            [[((TextFieldTableViewCell*)cell) getTextField] setKeyboardType:UIKeyboardTypeNumberPad];
            break;            
    }
    
    return cell;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    
}


@end
