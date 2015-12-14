//
//  Message.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverSender.h"
#import "JiverMessageModel.h"

@interface JiverMessage : JiverMessageModel

@property (retain) NSString *message;

@property (retain) JiverSender *sender;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

@property (retain) NSString *data;
@property (retain) NSDictionary *jsonObj;

@property (retain) NSString *tempId;

@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic;
- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

- (BOOL) hasSameSender:(JiverMessage *)msg;

- (NSString *)getSenderName;

- (void) mergeWith:(JiverMessage *)merge;

- (NSString *) toJson;

@end
