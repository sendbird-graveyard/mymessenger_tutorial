//
//  MessagingChannelUpdate.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 6. 17..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverMessagingChannelUpdate : NSObject

@property NSDictionary *jsonObj;
@property long long channelId;
@property BOOL messageUpdate;

- (id) initWithDic:(NSDictionary *) dic;
- (NSString *) toJson;
- (BOOL) isMessageUpdate;

@end
