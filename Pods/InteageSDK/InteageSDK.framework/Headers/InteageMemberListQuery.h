//
//  InteageMemberListQuery.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 5. 20..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageClient.h"

@class InteageClient;

/**
 *  Class for the list of members within the channel. This class is NOT used directly, and use [`queryMemberListInChannel:`](./Inteage.html#//api/name/queryMemberListInChannel:) of [`Inteage`](./Inteage.html) to create instances instead.
 */
@interface InteageMemberListQuery : NSObject

- (id) initWithClient:(InteageClient *)inteageClient andChannelUrl:(NSString *)chUrl;

/**
 *  Get the current page number
 *
 *  @return Current page
 */
- (int) getCurrentPage;

/**
 *  Get the next page number
 *
 *  @return Next page
 */
- (int) getNextPage;

/**
 *  Checks if the next page exists
 *
 *  @return Returns YES if the next page exists, otherwise returns NO
 */
- (BOOL) hasNext;

/**
 *  Check if the loading is in progress
 *
 *  @return Returns YES if loading is in progress, otherwise returns NO
 */
- (BOOL) isLoading;

- (void) setLoading:(BOOL) tf;

/**
 *  Returns the list of members. Upon retrieval, queryResult of onResult will contain the array of [`InteageMember`](./InteageMember.html). onError will be called if there is an error.
 *
 *  @param onResult Callback invoked upon retrieval of the member list
 *  @param onError  Callbakck invoked upon error
 */
- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

@end
