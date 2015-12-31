//
//  InteageSystemMessage.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageMessageModel.h"

#define kInteageCategoryNone 0
#define kInteageCategoryChannelJoin 10100
#define kInteageCategoryChannelLeave 10101
#define kInteageCategoryChannelInvite 10102
#define kInteageCategoryTooManyMessages 10200
#define kInteageCategoryMessagingUserBlocked 10300
#define kInteageCategoryMessagingUserDeactivated 10400

/**
 *  Class used for system messages. The object is returned when systemMessageReceived callback is invoked by [`setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Inteage.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) of [`Inteage`](./Inteage.html)
 */
@interface InteageSystemMessage : InteageMessageModel

/**
 *  Message body
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Message type
 *
 *  - Joined the channel  - 10100
 *  - Left the channel - 10101
 *  - Invited to the channel - 10102
 *  - Muted - 10500
 */
@property long long category;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (NSString *) toJson;

@end
