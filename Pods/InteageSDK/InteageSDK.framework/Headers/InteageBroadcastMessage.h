//
//  InteageBroadcastMessage.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 4. 10..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageMessageModel.h"

/**
 *  Class for broadcast messages. This class is comprised of message and additional data.
 */
@interface InteageBroadcastMessage : InteageMessageModel

/**
 *  Broadcast message
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Additional data
 */
@property (retain) NSString *data;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

- (NSString *) toJson;

@end
