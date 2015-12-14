//
//  JiverMessagingUnreadCountQuery.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 7. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverClient.h"

@interface JiverMessagingUnreadCountQuery : NSObject

- (id) initWithClient:(JiverClient *)jiverClient;
- (BOOL) isLoading;

- (void) executeWithResultBlock:(void (^)(int unreadMessageCount))onResult errorBlock:(void (^)(NSInteger code))onError;

@end
