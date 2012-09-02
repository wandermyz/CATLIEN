//
//  SliderTableViewCell.m
//  CATLIEN
//
//  Created by Wander on 9/1/12.
//
//

#import "SliderTableViewCell.h"

@implementation SliderTableViewCell
{
    UISlider* _slider;
    id<SliderDelegate> _delegate;
}

- (id)initWithDelegate:(id<SliderDelegate>)delegate resueIdentifier:(NSString *)reuseIdentifier 
{
    self = [super initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:reuseIdentifier];
    if (self)
    {
        _delegate = delegate;
        _slider = [[UISlider alloc] initWithFrame:CGRectMake(100, 0, 220, 40)];
        [_slider addTarget:self action:@selector(sliderValueChangedAction:) forControlEvents:UIControlEventValueChanged];
        
        [self addSubview:_slider];
        self.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    
    return self;
}

- (NSString *)label
{
    return self.textLabel.text;
}

- (void)setLabel: (NSString *)value
{
    self.textLabel.text = value;
}

- (UISlider *) slider
{
    return _slider;
}

- (IBAction)sliderValueChangedAction:(id)sender
{
    if (_delegate)
    {
        [_delegate slider:_slider valueChangedTo:_slider.value];
    }
}

- (NSInteger) tag
{
    return super.tag;
}

- (void) setTag: (NSInteger) value
{
    super.tag = value;
    _slider.tag = value;
}

@end
