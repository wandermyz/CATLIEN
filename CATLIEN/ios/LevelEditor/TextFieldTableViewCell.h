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
- (NSString *) getTextFieldValue;
- (void) setTextFieldValue: (NSString *) value;
- (NSString *) getLabel;
- (void) setLabel: (NSString *) value;
- (UITextField* ) getTextField;
@end
