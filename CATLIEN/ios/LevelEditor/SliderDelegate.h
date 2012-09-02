//
//  SliderDelegate.h
//  CATLIEN
//
//  Created by Wander on 9/1/12.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol SliderDelegate <NSObject>
@required
- (void) slider: (UISlider *)slider valueChangedTo: (float) value;
@end
