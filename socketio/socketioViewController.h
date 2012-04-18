//
//  socketioViewController.h
//  socketio
//
//  Created by Htain Lin Shwe on 25/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SocketIO.h"
@interface socketioViewController : UIViewController <SocketIODelegate>
@property(nonatomic,retain) IBOutlet UITextView* txtview;
@property(nonatomic,retain) IBOutlet UITextField* txtfield;
@property(nonatomic,retain) SocketIO* socektio;
@end
