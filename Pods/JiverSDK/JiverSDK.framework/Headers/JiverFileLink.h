//
//  FileLink.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverFileInfo.h"
#import "JiverSender.h"
#import "JiverMessageModel.h"
#import "JiverBlockedUser.h"

@interface JiverFileLink : JiverMessageModel

@property (retain) JiverSender *sender;

@property (retain) JiverFileInfo *fileInfo;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

@property (retain) NSDictionary *jsonObj;

@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

- (NSString *)getSenderName;

- (NSString *) toJson;

@end
