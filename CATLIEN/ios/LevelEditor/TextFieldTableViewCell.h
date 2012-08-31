//
//  TextFieldTableViewCell.h
//  CATLIEN
//
//  Created by Wander on 8/30/12.
//
//

#import <UIKit/UIKit.h>

@interface TextFieldTableViewCell : UITableViewCell
- (id)initWithLabel: (NSString* )label reuseIdentifier: (NSString *)reuseIdentifier delegate: (id<UITextFieldDelegate>) delegate;
- (NSString *) getTextFieldValue;
- (void) setTextFieldValue: (NSString *) value;
@end
