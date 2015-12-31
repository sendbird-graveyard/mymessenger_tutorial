//
//  InteageMessagingUnreadCountQuery.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 7. 20..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageClient.h"

/**
 *  Class used to retrieve the total unreal message count of the Messaging/Group messaging channel that the current user is in. This class is not used directly, but instead [`Inteage queryMessagingUnreadCount`](./Inteage.html#//api/name/queryMessagingUnreadCount) must be used to create instances.
 */
@interface InteageMessagingUnreadCountQuery : NSObject

- (id) initWithClient:(InteageClient *)inteageClient;

- (BOOL) isLoading;

/**
 *  Get the total unreal message count of the Messaging/Group messaging channel that the current user is in
 *
 *  @param onResult Callback invoked upon success
 *  @param onError  Callback invoked upon failure
 */
- (void) executeWithResultBlock:(void (^)(int unreadMessageCount))onResult errorBlock:(void (^)(NSInteger code))onError;

@end
