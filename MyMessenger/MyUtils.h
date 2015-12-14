//
//  MyUtils.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/6/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JiverSDK/JiverSDK.h>

@interface MyUtils : NSObject

+ (NSString *) lastMessageDateTime:(NSTimeInterval) interval;
+ (void) setUserName:(NSString *)userName;
+ (NSString *) getUserName;
+ (void) setUserProfileImage:(NSString *)profileImageUrl;
+ (NSString *) getUserProfileImage;
+ (NSString *)generateMessagingTitle:(JiverMessagingChannel *)channel;
+ (NSString *)generateMessagingChannelTitle:(JiverMessagingChannel *)channel;
+ (NSString *)generateTypingStatus:(NSMutableDictionary *)typeStatus;

@end
