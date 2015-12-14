//
//  JiverMessageListQuery.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 6. 26..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverMessageListQuery : NSObject

- (id) initWithJiverClient:(JiverClient *)client andChannelUrl:(NSString *)channelUrl;
- (BOOL) isLoading;

- (void) nextWithMessageTs:(long long)messageTs andLimit:(int)limit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

- (void) prevWithMessageTs:(long long)messageTs andLimit:(int)limit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

- (void) loadWithMessageTs:(long long)messageTs prevLimit:(int)prevLimit andNextLimit:(int)nextLimit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

@end
