//
//  InteageCommand.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 3..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageFileInfo.h"

@interface InteageCommand : NSObject

@property (retain) NSString *command;
@property (retain) NSString *payload;

- (id) initWithCommand:(NSString *)command andPayload:(NSString *)payload;
- (id) initWithCommand:(NSString *)command andDictionaryPayload:(NSDictionary *)payload;
- (void) decode:(NSString *)command;
- (NSDictionary *) getJson;
- (NSString *) encode;

+ (InteageCommand *)parse:(NSString *)data;
+ (InteageCommand *)bLoginWithUserKey:(NSString *)userKey;
+ (InteageCommand *)bJoinWithChannelId:(NSString *)channelId andLastMessageTs:(long long)lastMessageTs;
+ (InteageCommand *)bMessageWithChannelId:(long long)channelId andMessage:(NSString *)message andData:(NSString *)data tempId:(NSString *)tempId mentionedUserIds:(NSArray *)mentionedUserIds;
+ (InteageCommand *)bFileOfChannelWithChannelId:(long long)channelId andFileInfo:(InteageFileInfo *)fileInfo;
+ (InteageCommand *)bPing;
+ (InteageCommand *)bReadOfChannel:(long long)channelId andTime:(long long)time;
+ (InteageCommand *)bTypeStartOfChannel:(long long)channelId andTime:(long long)time;
+ (InteageCommand *)bTypeEndOfChannel:(long long)channelId andTime:(long long)time;

@end
