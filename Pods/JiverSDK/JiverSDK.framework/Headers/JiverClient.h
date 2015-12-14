//
//  JiverClient.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Jiver.h"
#import "JiverChannel.h"
#import "JiverMessage.h"
#import "JiverSystemMessage.h"
#import "JiverFileLink.h"
#import "JiverWSClient.h"
#import "JiverAPIClient.h"
#import "JiverCommand.h"
#import "JiverBroadcastMessage.h"
#import "JiverMessagingChannel.h"
#import "JiverReadStatus.h"
#import "JiverTypeStatus.h"
#import "JiverError.h"
#import "JiverMember.h"
#import "JiverWSClient.h"
#import "JiverMention.h"
#import "JiverStructuredMessage.h"

//extern void (^onMessageReceived)(JiverMessage *message);
//extern void (^onSystemMessageReceived)(JiverSystemMessage *message);
//extern void (^onBroadcastMessageReceived)(JiverBroadcastMessage *message);
//extern void (^onFileReceived)(JiverFileLink *fileLink);
//extern void (^onMessagingStarted)(JiverMessagingChannel *channel);
//extern void (^onMessagingUpdated)(JiverMessagingChannel *channel);
//extern void (^onMessagingEnded)(JiverMessagingChannel *channel);
//extern void (^onReadReceived)(JiverReadStatus *status);
//extern void (^onTypeStartReceived)(JiverTypeStatus *status);
//extern void (^onTypeEndReceived)(JiverTypeStatus *status);

//enum JiverDataType;

@interface JiverClient : NSObject

- (id) initWithAppId:(NSString *)appId;
- (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *tempId))messageDelivery;

// TODO
//- (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived structuredMessageReceivedBlock:(void (^)(JiverStructuredMessage *message))structuredMessageReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *tempId))messageDelivery;

- (NSString *) getUserID;
- (NSString *) getUserName;
//- (void) setLastMessageLimit:(int)limit;
- (void) setLoginInfoWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken andDeviceId:(NSString *)deviceId;
- (void) setChannelUrl:(NSString *)channelUrl;
- (NSString *) getChannelUrl;
- (JiverChannel *) getCurrentChannel;
- (void) connectWithMaxMessageTs:(long long)maxMessageTs;
- (void) cancelAll;
- (void) disconnect;
- (void) registerNotificationHandlerMessagingChannelUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingChannelUpdated mentionUpdatedBlock:(void (^)(JiverMention *mention))mentionUpdated;
- (void) unregisterNotificationHandlerMessagingChannelUpdatedBlock;
- (void) cmdMessage:(NSString *)message withData:(NSString *)data andTempId:(NSString *)tempId mentionedUserIds:(NSArray *)mentionedUserIds;
- (void) markAsRead;
- (void) markAsReadForChannelUrl:(NSString *)channelUrl;
- (void) markAllAsRead;
- (void) getChannelListInPage:(int)page withQuery:(NSString *)query withLimit:(int)limit resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
//- (void) getMessagingListWithResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) getMessagingListV2WithToken:(NSString *)token andPage:(int)page withLimit:(int)limit andShowEmpty:(BOOL)showEmpty resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) messageListInChannelUrl:(NSString *)channelUrl withMessageTs:(long long)messageTs prevLimit:(int)prevLimit andNextLimit:(int)nextLimit include:(BOOL)include resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) leaveChannel:(NSString *)channelUrl;
- (void) getBlockedUserListResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) uploadFile:(NSData *)file type:(NSString *)type size:(unsigned long)size customField:(NSString *)customField uploadBlock:(void (^)(JiverFileInfo *fileInfo, NSError *error))onUpload;
- (void) cmdFile:(JiverFileInfo *)fileInfo;
//- (void) saveCursor;
//- (long long) loadCursorWithChannelUrl:(NSString *)channelUrl;
//- (void) setLastMessageMills:(long long)lastMessageMills;
//- (long long) getLastMessageMills;
- (void) messageReceived:(JiverMessage *)msg;
- (void) systemMessageReceived:(JiverSystemMessage *)msg;
- (void) broadcastMessageReceived:(JiverBroadcastMessage *)msg;
- (void) fileReceived:(JiverFileLink *)fileLink;
- (void) messagingStarted:(JiverMessagingChannel *)channel;
- (void) messagingEnded:(JiverMessagingChannel *)channel;
- (void) endAllMessaging;
- (void) typeStart:(JiverTypeStatus *)status;
- (void) typeEnd:(JiverTypeStatus *)status;
- (void) startMessagingWithGuestIds:(NSArray *)guestIds;
- (void) endMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) hideMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) hideAllMessaging;
- (void) cmdRead;
- (void) cmdTypeStart;
- (void) cmdTypeEnd;
//- (void) loadPrevMessagesWithLimit:(int)limit;
//- (void) loadPrevMessagesWithMinMessageId:(long long)minMessageId andLimit:(int)limit;
//- (void) loadNextMessagesWithLimit:(int)limit;
//- (void) loadNextMessagesWithMaxMessageId:(long long)maxMessageId andLimit:(int)limit;
//- (void) endCursorMode;
//- (BOOL) isCursorMode;
//- (void) startCursorModeWithCursor:(long long)cursor prevLimit:(int)prevLimit andNextLimit:(int)nextLimit;
//- (void) loadMessagesWithCursor:(long long)cursor prevLimit:(int)prevLimit andNextLimit:(int)nextLimit;
//- (void) loadMoreMessagesWithLimit:(int)limit;
- (void) getMemberListInChannel:(NSString *)channelUrl withPageNum:(int)page withQuery:(NSString *)query withLimit:(int)limit resultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) getMessagingUnreadCountResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;
- (void) joinMessagingWithChannelUrl:(NSString *)channelUrl;
- (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andGuestIds:(NSArray *)guestIds;
//- (long long)getMaxMessageTs;
- (enum WSReadyState) connectState;
@end
