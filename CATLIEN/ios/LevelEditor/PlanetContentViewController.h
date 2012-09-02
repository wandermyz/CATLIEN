//
//  PlanetContentViewController.h
//  CATLIEN
//
//  Created by Wander on 8/31/12.
//
//

#import <UIKit/UIKit.h>
#import "SliderDelegate.h"
#include "../../Classes/GameObjects/Planet.h"

@interface PlanetContentViewController : UITableViewController<UITextFieldDelegate, SliderDelegate>
- (id) initWithPlanet: (Planet *)planet;
@end
