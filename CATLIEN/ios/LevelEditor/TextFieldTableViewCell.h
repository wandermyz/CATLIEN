//
//  TextFieldTableViewCell.h
//  CATLIEN
//
//  Created by Wander on 8/30/12.
//
//

#import <UIKit/UIKit.h>

@interface TextFieldTableViewCell : UITableViewCell
- (id)initWithDelegate: (id<UITextFieldDelegate>) delegate reuseIdentifier: (NSString *)reuseIdentifier;

@property (getter=label, setter=setLabel:, assign) NSString* label;
@property (getter=tag, setter=setTag:, assign) NSInteger tag;
@property (getter=textField, readonly) UITextField* textField;

@end
