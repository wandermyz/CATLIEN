//
//  PlanetContentViewController.m
//  CATLIEN
//
//  Created by Wander on 8/31/12.
//
//

#import "PlanetContentViewController.h"
#import "TextFieldTableViewCell.h"
#import "SliderTableViewCell.h"

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
    return 4;
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
                cell = [[[SliderTableViewCell alloc] initWithDelegate:self resueIdentifier:@"Slider"] autorelease];
            }
            break;
    }
    
    switch (indexPath.row)
    {
        case PLANET_ROW_TEXTURE:
        {
            TextFieldTableViewCell* textFieldCell = (TextFieldTableViewCell*)cell;
            textFieldCell.label = @"Texture";
            textFieldCell.textField.text = [NSString stringWithUTF8String:_planet->getTexturePath().c_str()];
            break;
        }
            
        case PLANET_ROW_FRAME_COUNT:
        {
            TextFieldTableViewCell* textFieldCell = (TextFieldTableViewCell*)cell;
            textFieldCell.label = @"Frames";
            [textFieldCell.textField setKeyboardType:UIKeyboardTypeNumberPad];
            textFieldCell.textField.text = [NSString stringWithFormat:@"%d", _planet->getFrameCount()];
            break;
        }
            
        case PLANET_ROW_RADIUS:
        {
            SliderTableViewCell* radiusCell = (SliderTableViewCell*) cell;
            radiusCell.label = @"Radius";
            radiusCell.slider.minimumValue = 20.0f;
            radiusCell.slider.maximumValue = 1000.0f;
            radiusCell.slider.value = _planet->getRadius();
            break;
        }
            
        case PLANET_ROW_DENSITY:
        {
            SliderTableViewCell* densityCell = (SliderTableViewCell*) cell;
            densityCell.label=@"Density";
            densityCell.slider.minimumValue = 0.2f;
            densityCell.slider.maximumValue = 10.0f;
            densityCell.slider.value = _planet->getDensity();
            break;
        }
    }
    
    cell.tag = indexPath.row;
    
    return cell;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    switch (textField.tag)
    {
        case PLANET_ROW_TEXTURE:
            _planet->setTexturePath([textField.text UTF8String]);
            break;
            
        case PLANET_ROW_FRAME_COUNT:
            _planet->setFrameCount([textField.text intValue]);
            break;
    }
}

- (void)slider:(UISlider *)slider valueChangedTo:(float)value
{
    switch (slider.tag) {
        case PLANET_ROW_RADIUS:
            _planet->setRadius(slider.value);
            break;
            
        case PLANET_ROW_DENSITY:
            _planet->setDensity(slider.value);
            break;
    }
}


@end
