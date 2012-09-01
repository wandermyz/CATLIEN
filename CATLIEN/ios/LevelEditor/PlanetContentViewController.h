//
//  PlanetContentViewController.h
//  CATLIEN
//
//  Created by Wander on 8/31/12.
//
//

#import <UIKit/UIKit.h>
#include "../../Classes/GameObjects/Planet.h"

@interface PlanetContentViewController : UITableViewController<UITextFieldDelegate>
- (id) initWithPlanet: (Planet *)planet;
@end
