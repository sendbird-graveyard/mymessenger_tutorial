//
//  ChannelListQuery.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 3. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverClient.h"

@class JiverClient;

@interface JiverChannelListQuery : NSObject<NSURLConnectionDataDelegate>

@property (retain) NSString *query;

@property int page;

@property int nextPage;

@property int limit;

- (id) initWithClient:(JiverClient *)jiverClient;

- (BOOL) hasNext;

- (BOOL) isLoading;

- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

- (JiverClient *) getClient;

@end
