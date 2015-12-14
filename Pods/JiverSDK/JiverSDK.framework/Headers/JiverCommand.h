//
//  Command.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 3..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverFileInfo.h"

@interface JiverCommand : NSObject

@property (retain) NSString *command;
@property (retain) NSString *payload;

- (id) initWithCommand:(NSString *)command andPayload:(NSString *)payload;
- (id) initWithCommand:(NSString *)command andDictionaryPayload:(NSDictionary *)payload;
- (void) decode:(NSString *)command;
- (NSDictionary *) getJson;
- (NSString *) encode;

+ (JiverCommand *)parse:(NSString *)data;
+ (JiverCommand *)bLoginWithUserKey:(NSString *)userKey;
+ (JiverCommand *)bJoinWithChannelId:(NSString *)channelId andLastMessageTs:(long long)lastMessageTs;
+ (JiverCommand *)bMessageWithChannelId:(long long)channelId andMessage:(NSString *)message andData:(NSString *)data tempId:(NSString *)tempId mentionedUserIds:(NSArray *)mentionedUserIds;
+ (JiverCommand *)bFileOfChannelWithChannelId:(long long)channelId andFileInfo:(JiverFileInfo *)fileInfo;
+ (JiverCommand *)bPing;
+ (JiverCommand *)bReadOfChannel:(long long)channelId andTime:(long long)time;
+ (JiverCommand *)bTypeStartOfChannel:(long long)channelId andTime:(long long)time;
+ (JiverCommand *)bTypeEndOfChannel:(long long)channelId andTime:(long long)time;

@end
