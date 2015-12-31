//
//  InteageMessagingChannelUpdate.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 6. 17..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InteageMessagingChannelUpdate : NSObject

@property NSDictionary *jsonObj;
@property long long channelId;
@property BOOL messageUpdate;

- (id) initWithDic:(NSDictionary *) dic;
- (NSString *) toJson;
- (BOOL) isMessageUpdate;

@end
