//
//  Jiver.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdSupport/AdSupport.h>
#import "JiverClient.h"
#import "JiverFileInfo.h"
#import "JiverChannelListQuery.h"
#import "JiverAPIClient.h"
#import "JiverBroadcastMessage.h"
#import "JiverMessagingChannel.h"
#import "JiverReadStatus.h"
#import "JiverTypeStatus.h"
#import "JiverMessagingChannelListQuery.h"
#import "JiverMemberListQuery.h"
#import "JiverMessageListQuery.h"
#import "JiverSystemMessage.h"
#import "JiverWSClient.h"
#import "JiverMessagingUnreadCountQuery.h"
#import "JiverMention.h"
#import "JiverStructuredMessage.h"
#import "JiverBlockedUser.h"

#define kJiverInitWithIDFA 0
#define kJiverInitWithIDFV 1

typedef enum {
    JiverDataTypeNone,
//    JiverDataTypeJoin = 0,
//    JiverDataTypeLoadMore = 1,
//    JiverDataTypeLoadNext,
//    JiverDataTypeLoadPrev,
//    JiverDataTypeLoadWithCursor,
    JiverDataTypeMessage,
    JiverDataTypeSystemMessage,
    JiverDataTypeBroadcastMessage,
    JiverDataTypeFileLink,
    JiverDataTypeReadStatus,
    JiverDataTypeStartTyping,
    JiverDataTypeEndTyping,
    JiverDataTypeStructuredMessage,
} JiverDataType;

@class JiverChannelListQuery;
@class JiverClient;
@class JiverMessagingChannelListQuery;
@class JiverMemberListQuery;
@class JiverFileInfo;
@class JiverFileLink;
@class JiverMessagingUnreadCountQuery;

@interface Jiver : NSObject

+ (NSString *) VERSION;

+ (BOOL) JIVER_LOG_DEBUG;

+ (NSString *) WS_HOST;

+ (NSString *) API_HOST;

+ (Jiver *) sharedInstance;

+ (JiverBlockedUser *) jiverBlockedUser;

+ (void) setJiverBlockedUser:(JiverBlockedUser *)newJiverBlockedUser;

@property (retain) NSString *appId;

@property BOOL connected;

@property BOOL mLoginRequired;

@property (retain) NSOperationQueue *taskQueue;

@property (retain) NSOperationQueue *imageTaskQueue;

- (id) initWithAppId:(NSString *)appId;

+ (void) initWithAppKey:(NSString *)appKey;

+ (void) initByIDFVWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initByIDFAWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId withBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId andAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

+ (void) initAppId:(NSString *)appId;

+ (void) initAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

+ (void) initAppId:(NSString *)appId withDeviceId:(NSString *)deviceId ;

+ (void) igawInitByIDFVWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFAWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId withBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFVWithAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFAWithAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId andAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

+ (void) igawInitAppId:(NSString *)appId;

+ (void) igawInitAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

+ (void) igawInitAppId:(NSString *)appId withDeviceId:(NSString *)deviceId;

+ (void) loginWithUserName:(NSString *)userName;

+ (void) loginWithUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl;

+ (void) igawLoginWithUserId:(NSString *)userId;

+ (void) igawLoginWithUserName:(NSString *)userName;

+ (void) igawLoginWithUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl;

+ (void) igawLoginWithUserId:(NSString *)userId andAccessToken:(NSString *)accessToken;

+ (void) igawLoginWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken;

+ (void) loginWithUserId:(NSString *)userId andUserName:(NSString *)userName;

+ (void) loginWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken;

+ (void) joinChannel:(NSString *)channelUrl;

+ (void) leaveChannel:(NSString *)channelUrl;

+ (NSString *) getChannelUrl;

+ (NSString *) getUserId;

+ (NSString *) getUserName;

+ (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *messageId))messageDelivery;

// TODO:
//+ (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived structuredMessageReceivedBlock:(void (^)(JiverStructuredMessage *message))structuredMessageReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *messageId))messageDelivery;

+ (JiverChannel *) getCurrentChannel;

+ (void) startMessagingWithUserId:(NSString *)userId;

+ (void) startMessagingWithUserIds:(NSArray *)userIds;

+ (void) joinMessagingWithChannelUrl:(NSString *)channelUrl;

+ (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andUserId:(NSString *)userId;

+ (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andUserIds:(NSArray *)userIds;

+ (void) endMessagingWithChannelUrl:(NSString *)channelUrl;

+ (void) endAllMessaging;

+ (void) hideMessagingWithChannelUrl:(NSString *)channelUrl;

+ (void) hideAllMessaging;

+ (void) typeStart;

+ (void) typeEnd;

+ (void) markAsRead;

+ (void) markAsReadForChannel:(NSString *)channelUrl;

+ (void) markAllAsRead;

+ (void) connect;

+ (void) connectWithMessageTs:(long long)messageTs;

+ (void) cancelAll;

+ (void) disconnect;

+ (void) registerNotificationHandlerMessagingChannelUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingChannelUpdated mentionUpdatedBlock:(void (^)(JiverMention *mention))mentionUpdated;

+ (void) unregisterNotificationHandlerMessagingChannelUpdatedBlock;

+ (void) sendMessage:(NSString *)message;

+ (void) sendMessage:(NSString *)message withTempId:(NSString *)tempId;

+ (void) sendMessage:(NSString *)message withData:(NSString *)data;

+ (void) sendMessage:(NSString *)message withData:(NSString *)data andTempId:(NSString *)tempId;

+ (void) sendMessage:(NSString *)message withData:(NSString *)data andTempId:(NSString *)tempId mentionedUserIds:(NSArray *)mentionedUserIds;

+ (void) sendFile:(JiverFileInfo *)fileInfo;

+ (void) uploadFile:(NSData *)file type:(NSString *)type hasSizeOfFile:(unsigned long)size withCustomField:(NSString *)customField uploadBlock:(void (^)(JiverFileInfo *fileInfo, NSError *error))onUpload;

+ (JiverMessagingChannelListQuery *) queryMessagingChannelList;

+ (JiverChannelListQuery *) queryChannelList;

+ (JiverChannelListQuery *) queryChannelListWithKeyword:(NSString *)keyword;

+ (JiverChannelListQuery *) queryChannelListForUnity;

+ (JiverMemberListQuery *) queryMemberListInChannel:(NSString *)channelUrl;

+ (JiverMessageListQuery *) queryMessageListInChannel:(NSString *)channelUrl;

+ (JiverMessagingUnreadCountQuery *) queryMessagingUnreadCount;

+ (void) messageReceived:(JiverMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) fileReceived:(JiverFileLink *)fileLink DEPRECATED_ATTRIBUTE;

+ (void) broadcastMessageReceived:(JiverBroadcastMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) systemMessageReceived:(JiverSystemMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) messagingStarted:(JiverMessagingChannel *)channel DEPRECATED_ATTRIBUTE;

+ (void) messagingEnded:(JiverMessagingChannel *)channel DEPRECATED_ATTRIBUTE;

+ (NSString *) deviceUniqueID;

+ (enum WSReadyState) connectState;

/**
 *  For UnitTest
 */
+ (void) testUserBlockListResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;

@end
