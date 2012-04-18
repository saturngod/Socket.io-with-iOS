//
//  socketioAppDelegate.h
//  socketio
//
//  Created by Htain Lin Shwe on 25/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class socketioViewController;

@interface socketioAppDelegate : NSObject <UIApplicationDelegate>

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet socketioViewController *viewController;

@end
