//
//  EditorPanelControllerViewController.h
//  CATLIEN
//
//  Created by Wander on 8/28/12.
//
//

#import <UIKit/UIKit.h>
#import "../../Classes/GameObjects/GameObject.h"

@interface EditorPanelController : UITableViewController<UITextFieldDelegate>
- initWithGameObject: (GameObject *) gameObject;
@end
