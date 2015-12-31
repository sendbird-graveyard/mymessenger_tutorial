//
//  InteageMessage.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageSender.h"
#import "InteageMessageModel.h"

/**
 *  Class for messaging. Used in callbacks retrieving the messages.
 *
 *  - Returns from `messageReceived` callback in [`setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Inteage.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) of [`Inteage`](./Inteage.html)
 *  - Returns as a part of `queryResult` from `onResult` in [`nextWithMessageTs:andLimit:resultBlock:endBlock:`](./InteageMessageListQuery.html#//api/name/nextWithMessageTs:andLimit:resultBlock:endBlock:), [`prevWithMessageTs:andLimit:resultBlock:endBlock:`](./InteageMessageListQuery.html#//api/name/prevWithMessageTs:andLimit:resultBlock:endBlock:), [`loadWithMessageTs:prevLimit:andNextLimit:resultBlock:endBlock:`](./InteageMessageListQuery.html#//api/name/loadWithMessageTs:prevLimit:andNextLimit:resultBlock:endBlock:) of [`InteageMessageListQuery`](./InteageMessageListQuery.html)
 */

@interface InteageMessage : InteageMessageModel

/**
 *  Message body
 */
@property (retain) NSString *message;

/**
 *  Message sender
 */
@property (retain) InteageSender *sender;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

/**
 *  Additional data sent along with the message
 */
@property (retain) NSString *data;

@property (retain) NSDictionary *jsonObj;

/**
 *  Message ID used for verifying successful delivery
 */
@property (retain) NSString *tempId;

/**
 *  Returns YES if the user is blocked, otherwise returns NO
 */
@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

/**
 *  Method used for checking if the senders are the same person
 *
 *  @param msg Message to compare
 *
 *  @return Returns YES if the same, otherwise returns NO
 */
- (BOOL) hasSameSender:(InteageMessage *)msg;

/**
 *  Returns the name of the sender
 *
 *  @return User name of the sender
 */
- (NSString *)getSenderName;

- (void) mergeWith:(InteageMessage *)merge DEPRECATED_ATTRIBUTE;

- (NSString *) toJson;

@end
