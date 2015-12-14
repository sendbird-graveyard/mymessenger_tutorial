//
//  MemberListQuery.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 5. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverClient.h"

@class JiverClient;

@interface JiverMemberListQuery : NSObject

- (id) initWithClient:(JiverClient *)jiverClient andChannelUrl:(NSString *)chUrl;

- (int) getCurrentPage;

- (int) getNextPage;

- (BOOL) hasNext;

- (BOOL) isLoading;

- (void) setLoading:(BOOL) tf;

- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

@end
