//
//  OrderedModel.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 24..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverMessageModel : NSObject

- (id) init;

- (void) setPresent:(BOOL)tf;

- (BOOL) isPast;

- (BOOL) isPresent;

- (BOOL) hasMessageId;

- (long long) getMessageId;

- (long long) parseMessageId:(NSDictionary *)dic;

- (long long) getMessageTimestamp;

- (long long) parseMessageTimestamp:(NSDictionary *)dic;

+ (JiverMessageModel *) parseData:(NSString *)data isPresent:(BOOL)present;

@end
