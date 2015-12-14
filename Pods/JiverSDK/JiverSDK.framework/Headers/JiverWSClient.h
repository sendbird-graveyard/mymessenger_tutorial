//
//  WSClient.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 3. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SRWebSocket.h"
#import "JiverCommand.h"
#import "Jiver.h"

enum WSReadyState {
    WS_CONNECTING   = 0,
    WS_OPEN         = 1,
    WS_CLOSING      = 2,
    WS_CLOSED       = 3,
};

@interface JiverWSClient : NSObject<SRWebSocketDelegate>

- (id) initWithHost:(NSString *)host;
- (void) setEventHandlerOpenBlock:(void (^)())open messageBlock:(void (^)(NSString *data))message closeBlock:(void (^)())close errorBlock:(void (^)())error;
- (void) disconnect;
- (void) connect;
- (BOOL) sendCommand:(JiverCommand *)command;
- (enum WSReadyState) connectState;

@end
