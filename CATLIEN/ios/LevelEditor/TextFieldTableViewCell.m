//
//  TextFieldTableViewCell.m
//  CATLIEN
//
//  Created by Wander on 8/30/12.
//
//

#import "TextFieldTableViewCell.h"

@implementation TextFieldTableViewCell
{
    UITextField* _textField;
}


- (id)initWithDelegate: (id<UITextFieldDelegate>) delegate reuseIdentifier: (NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:reuseIdentifier];
    if (self) {
        
        _textField = [[UITextField alloc] initWithFrame:CGRectMake(100, 0, 220, 40)];
        _textField.textAlignment = UITextAlignmentRight;
        _textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        _textField.autocorrectionType = UITextAutocorrectionTypeNo;
        _textField.autocapitalizationType = UITextAutocapitalizationTypeNone;
        _textField.clearButtonMode = UITextFieldViewModeNever;
        _textField.delegate = delegate;
        
        [self addSubview:_textField];
        self.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (UITextField *) textField
{
    return _textField;
}

- (NSInteger) tag
{
    return super.tag;
}

- (void) setTag: (NSInteger) value
{
    super.tag = value;
    _textField.tag = value;
}

- (NSString *)label
{
    return self.textLabel.text;
}

- (void)setLabel: (NSString *)value
{
    self.textLabel.text = value;
}

@end
