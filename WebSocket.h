//
//  WebSocket.h
//  Zimt
//
//  Created by Esad Hajdarevic on 2/14/10.
//  Copyright 2010 OpenResearch Software Development OG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AsyncSocket;
@class WebSocket;

@protocol WebSocketDelegate<NSObject>
@optional 
    - (void)webSocket:(WebSocket*)webSocket didFailWithError:(NSError*)error;
    - (void)webSocketDidOpen:(WebSocket*)webSocket;
    - (void)webSocketDidClose:(WebSocket*)webSocket;
    - (void)webSocket:(WebSocket*)webSocket didReceiveMessage:(NSString*)message;
    - (void)webSocketDidSendMessage:(WebSocket*)webSocket;
@end

@interface WebSocket : NSObject {
    id<WebSocketDelegate> delegate;
    NSURL* url;
    AsyncSocket* socket;
    BOOL connected;
    NSString* origin;
    
    NSArray* runLoopModes;
}

@property(nonatomic,assign) id<WebSocketDelegate> delegate;
@property(nonatomic,readonly) NSURL* url;
@property(nonatomic,retain) NSString* origin;
@property(nonatomic,readonly) BOOL connected;
@property(nonatomic,retain) NSArray* runLoopModes;

+ (id)webSocketWithURLString:(NSString*)urlString delegate:(id<WebSocketDelegate>)delegate;
- (id)initWithURLString:(NSString*)urlString delegate:(id<WebSocketDelegate>)delegate;

- (void)open;
- (void)close;
- (void)send:(NSString*)message;

@end

enum {
    WebSocketErrorConnectionFailed = 1,
    WebSocketErrorHandshakeFailed = 2
};

extern NSString *const WebSocketException;
extern NSString* const WebSocketErrorDomain;
