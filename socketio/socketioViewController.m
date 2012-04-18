//
//  socketioViewController.m
//  socketio
//
//  Created by Htain Lin Shwe on 25/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "socketioViewController.h"
#import "SBJson.h"
@implementation socketioViewController
@synthesize socektio;
@synthesize txtview,txtfield;

-(void)dealloc {
    [socektio release];
    [super dealloc];
}
- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    socektio = [[SocketIO alloc] initWithDelegate:self];
    [socektio connectToHost:@"192.168.1.86" onPort:3000];
}


- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}


#pragma mark - API
- (void) socketIO:(SocketIO *)socket didReceiveEvent:(SocketIOPacket *)packet
{
    //NSLog(@"didReceiveMessage() >>> data: %@", packet.data);
    NSDictionary* data=[packet.data JSONValue];
    NSArray* arr=[data objectForKey:@"args"];
    NSString* str=[NSString stringWithFormat:@"\n[%@]:%@",[arr objectAtIndex:0],[arr objectAtIndex:1]];
    txtview.text = [txtview.text stringByAppendingString:str];
    
}

//- (void) socketIO:(SocketIO *)socket didReceiveJSON:(SocketIOPacket *)packet {
//    NSLog(@"JSON didReceiveMessage() >>> data: %@", packet.data);
//}
@end
