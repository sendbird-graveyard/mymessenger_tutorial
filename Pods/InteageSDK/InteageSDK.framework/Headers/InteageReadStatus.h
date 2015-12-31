//
//  InteageReadStatus.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 4. 20..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageUser.h"

/**
 *  Class used for handling read receipts of a user within Messaging/Group messaging channel. This class is returned when `readReceivedBlock` callback of [`Inteage setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Inteage.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:)is called, and this callback is invoked when another user in the channel calls [`markAsRead`](./Inteage.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Inteage.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Inteage.html#//api/name/markAllAsRead).
 */
@interface InteageReadStatus : NSObject

/**
 *  User who called [`markAsRead`](./Inteage.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Inteage.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Inteage.html#//api/name/markAllAsRead) after joining the channel
 */
@property (retain) InteageUser *user;

/**
 *  Timestamp when the user called [`markAsRead`](./Inteage.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Inteage.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Inteage.html#//api/name/markAllAsRead)
 */
@property long long timestamp;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

/**
 *  Returns a unique identifier [`InteageUser`](./InteageUser.html)의 [`guestId`](./InteageUser.html#//api/name/guestId)
 *
 *  @return [`InteageUser guestId`](./InteageUser.html#//api/name/guestId)
 */
- (NSString *) getUserId;

- (NSString *) toJson;

@end
