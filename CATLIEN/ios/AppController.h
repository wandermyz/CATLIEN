//
//  CATLIENAppController.h
//  CATLIEN
//
//  Created by Wander on 8/18/12.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//

#import "LevelEditor/LevelEditorManager.h"
@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController *viewController;
}

@end

