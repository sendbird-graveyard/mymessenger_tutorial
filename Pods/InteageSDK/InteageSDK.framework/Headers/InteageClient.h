//
//  InteageClient.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Inteage.h"
#import "InteageChannel.h"
#import "InteageMessage.h"
#import "InteageSystemMessage.h"
#import "InteageFileLink.h"
#import "InteageWSClient.h"
#import "InteageAPIClient.h"
#import "InteageCommand.h"
#import "InteageBroadcastMessage.h"
#import "InteageMessagingChannel.h"
#import "InteageReadStatus.h"
#import "InteageTypeStatus.h"
#import "InteageError.h"
#import "InteageMember.h"
#import "InteageWSClient.h"
#import "InteageMention.h"
#import "InteageStructuredMessage.h"

//extern void (^onMessageReceived)(InteageMessage *message);
//extern void (^onSystemMessageReceived)(InteageSystemMessage *message);
//extern void (^onBroadcastMessageReceived)(InteageBroadcastMessage *message);
//extern void (^onFileReceived)(InteageFileLink *fileLink);
//extern void (^onMessagingStarted)(InteageMessagingChannel *channel);
//extern void (^onMessagingUpdated)(InteageMessagingChannel *channel);
//extern void (^onMessagingEnded)(InteageMessagingChannel *channel);
//extern void (^onReadReceived)(InteageReadStatus *status);
//extern void (^onTypeStartReceived)(InteageTypeStatus *status);
//extern void (^onTypeEndReceived)(InteageTypeStatus *status);

//enum InteageDataType;

@interface InteageClient : NSObject

- (id) initWithAppId:(NSString *)appId;
- (void) setEventHandlerConnectBlock:(void (^)(InteageChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(InteageChannel *channel))channelLeft messageReceivedBlock:(void (^)(InteageMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(InteageSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(InteageBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(InteageFileLink *fileLink))fileReceived messagingStartedBlock:(void (^)(InteageMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(InteageMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(InteageMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(InteageMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(InteageReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(InteageTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(InteageTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger inteageDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *tempId))messageDelivery;

// TODO
//- (void) setEventHandlerConnectBlock:(void (^)(InteageChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(InteageChannel *channel))channelLeft messageReceivedBlock:(void (^)(InteageMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(InteageSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(InteageBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(InteageFileLink *fileLink))fileReceived structuredMessageReceivedBlock:(void (^)(InteageStructuredMessage *message))structuredMessageReceived messagingStartedBlock:(void (^)(InteageMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(InteageMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(InteageMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(InteageMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(InteageReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(InteageTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(InteageTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger inteageDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *tempId))messageDelivery;

- (NSString *) getUserID;
- (NSString *) getUserName;
//- (void) setLastMessageLimit:(int)limit;
- (void) setLoginInfoWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken andDeviceId:(NSString *)deviceId;
- (void) setChannelUrl:(NSString *)channelUrl;
- (NSString *) getChannelUrl;
- (InteageChannel *) getCurrentChannel;
- (void) connectWithMaxMessageTs:(long long)maxMessageTs;
- (void) cancelAll;
- (void) disconnect;
- (void) registerNotificationHandlerMessagingChannelUpdatedBlock:(void (^)(InteageMessagingChannel *channel))messagingChannelUpdated mentionUpdatedBlock:(void (^)(InteageMention *mention))mentionUpdated;
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
- (void) uploadFile:(NSData *)file type:(NSString *)type size:(unsigned long)size customField:(NSString *)customField uploadBlock:(void (^)(InteageFileInfo *fileInfo, NSError *error))onUpload;
- (void) cmdFile:(InteageFileInfo *)fileInfo;
//- (void) saveCursor;
//- (long long) loadCursorWithChannelUrl:(NSString *)channelUrl;
//- (void) setLastMessageMills:(long long)lastMessageMills;
//- (long long) getLastMessageMills;
- (void) messageReceived:(InteageMessage *)msg;
- (void) systemMessageReceived:(InteageSystemMessage *)msg;
- (void) broadcastMessageReceived:(InteageBroadcastMessage *)msg;
- (void) fileReceived:(InteageFileLink *)fileLink;
- (void) messagingStarted:(InteageMessagingChannel *)channel;
- (void) messagingEnded:(InteageMessagingChannel *)channel;
- (void) endAllMessaging;
- (void) typeStart:(InteageTypeStatus *)status;
- (void) typeEnd:(InteageTypeStatus *)status;
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
