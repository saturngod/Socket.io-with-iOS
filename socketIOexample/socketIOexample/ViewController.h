//
//  ViewController.h
//  socketIOexample
//
//  Created by Htain Lin Shwe on 21/10/13.
//  Copyright (c) 2013 saturngod. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SocketIO.h"
@interface ViewController : UIViewController <SocketIODelegate>
@property (nonatomic,strong) SocketIO* socketIO;

@property (nonatomic,assign) IBOutlet UITextView* chatLog;
@property (nonatomic,assign) IBOutlet UITextField* chatbox;

-(IBAction)sendMsg:(id)sender;
@end
