//
//  InteageWSClient.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 3. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageSRWebSocket.h"
#import "InteageCommand.h"
#import "Inteage.h"

enum WSReadyState {
    WS_CONNECTING   = 0,
    WS_OPEN         = 1,
    WS_CLOSING      = 2,
    WS_CLOSED       = 3,
};

@interface InteageWSClient : NSObject<InteageSRWebSocketDelegate>

- (id) initWithHost:(NSString *)host;
- (void) setEventHandlerOpenBlock:(void (^)())open messageBlock:(void (^)(NSString *data))message closeBlock:(void (^)())close errorBlock:(void (^)())error;
- (void) disconnect;
- (void) connect;
- (BOOL) sendCommand:(InteageCommand *)command;
- (enum WSReadyState) connectState;

@end
