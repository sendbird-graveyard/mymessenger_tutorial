//
//  MyUtils.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/6/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <InteageSDK/InteageSDK.h>

@interface MyUtils : NSObject

+ (NSString *) lastMessageDateTime:(NSTimeInterval) interval;
+ (void) setUserName:(NSString *)userName;
+ (NSString *) getUserName;
+ (void) setUserProfileImage:(NSString *)profileImageUrl;
+ (NSString *) getUserProfileImage;
+ (NSString *)generateMessagingTitle:(InteageMessagingChannel *)channel;
+ (NSString *)generateMessagingChannelTitle:(InteageMessagingChannel *)channel;
+ (NSString *)generateTypingStatus:(NSMutableDictionary *)typeStatus;

@end
