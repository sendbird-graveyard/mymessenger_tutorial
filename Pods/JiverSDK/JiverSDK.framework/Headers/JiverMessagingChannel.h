//
//  MessagingChannel.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverChannel.h"
#import "JiverMessage.h"

@interface JiverMessagingChannel : NSObject

@property (retain) JiverChannel *channel;

@property (retain) NSDictionary *jsonObj;

@property (retain) NSMutableArray *members;

@property (retain) NSMutableDictionary *readStatus;

@property int unreadMessageCount;

@property (retain) JiverMessage *lastMessage;

@property int messageCountSinceJoined;

@property int channelType;

- (id) initWithDic:(NSDictionary *) dic;
- (NSString *) toJson;

- (long long) getLastReadMillis:(NSString *)userId;

- (long long) getId;

- (BOOL) isGroupMessagingChannel;

- (BOOL) isMessagingChannel;

- (NSString *) getUrl;

- (NSString *) getUrlWithoutAppPrefix;

- (NSString *) getCoverUrl;

- (unsigned long) getMemberCount;

- (BOOL) hasLastMessage;

- (long long) getLastMessageTimestamp;

- (void) updateLastMessage:(NSString *) messageJson;

- (void) updateUnreadMessageCount:(int) count;

- (NSString *) getName;

- (long long) getCreatedAt;

@end
