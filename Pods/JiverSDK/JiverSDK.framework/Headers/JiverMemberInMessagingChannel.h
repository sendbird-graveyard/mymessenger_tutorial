//
//  MemberInMessagingChannel.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverMemberInMessagingChannel : NSObject

@property long long memberId;

@property (retain) NSString *name;

@property (retain) NSString *imageUrl;

@property (retain) NSString *guestId;

@property long long lastReadMillis;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *) dic;

- (NSString *) toJson;

@end
