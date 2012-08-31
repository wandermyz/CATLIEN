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
    UITextField* _nameTextField;
}


- (id)initWithLabel: (NSString* )label reuseIdentifier: (NSString *)reuseIdentifier delegate: (id<UITextFieldDelegate>) delegate
{
    self = [super initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:reuseIdentifier];
    if (self) {
        
        _nameTextField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 220, 30)];
        _nameTextField.textAlignment = UITextAlignmentRight;
        _nameTextField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        _nameTextField.autocorrectionType = UITextAutocorrectionTypeNo;
        _nameTextField.autocapitalizationType = UITextAutocapitalizationTypeNone;
        _nameTextField.clearButtonMode = UITextFieldViewModeNever;
        _nameTextField.delegate = delegate;
        
        self.textLabel.text = label;
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.accessoryView = _nameTextField;
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (NSString *) getTextFieldValue
{
    return _nameTextField.text;
}

- (void) setTextFieldValue:(NSString *)value
{
    _nameTextField.text = value;
}

@end
