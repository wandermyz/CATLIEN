//
//  SliderTableViewCell.h
//  CATLIEN
//
//  Created by Wander on 9/1/12.
//
//

#import <UIKit/UIKit.h>
#import "SliderDelegate.h"

@interface SliderTableViewCell : UITableViewCell
- (id)initWithDelegate: (id<SliderDelegate>) delegate resueIdentifier: (NSString *)reuseIdentifier;

@property (getter=slider, readonly) UISlider* slider;
@property (getter=tag, setter=setTag:, assign) NSInteger tag;
@property (getter=label, setter=setLabel:, assign) NSString* label;

@end
