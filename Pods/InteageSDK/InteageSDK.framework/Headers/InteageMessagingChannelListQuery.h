//
//  InteageMessagingChannelListQuery.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 6. 26..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageClient.h"

@class InteageClient;

/**
 *  Class used to retrieve the list of Messaging/Group messaging channels that the current user is in. This class is not used directly, but instead [`Inteage queryMessagingChannelList`](./Inteage.html#//api/name/queryMessagingChannelList) must be used. The class supports Pagination, by assigning [`setLimit:`](./InteageMessagingChannelListQuery.html#//api/name/setLimit:), then calling [`nextWithResultBlock:endBlock:`](./InteageMessagingChannelListQuery.html#//api/name/nextWithResultBlock:endBlock:) repeatedly to get next results. If there is no more page to be shown, [`hasNext`](./InteageMessagingChannelListQuery.html#//api/name/hasNext) value becomes NO.
 */
@interface InteageMessagingChannelListQuery : NSObject

- (id) initWithClient:(InteageClient *)inteageClient;

- (BOOL) isLoading;

/**
 *  Set the number of channels per page (limit)
 *
 *  @param lmt Number of channels per page
 */
- (void) setLimit:(int) lmt;

/**
 *  Stop retrieving the channel list
 */
- (void) cancel;

/**
 *  Check if there is more channels to retrieve
 *
 *  @return Returns YES if there is a next page, otherwise returns NO
 */
- (BOOL) hasNext;

/**
 *  Get the list of Messaging/Group messaging channels the current user is in
 *
 *  @param onResult Callback invoked upon success. queryResult is an array of [`InteageMessagingChannel`](./InteageMessagingChannel.html)
 *  @param onError  Callback invoked upon error
 */
- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSInteger code))onError;

@end
