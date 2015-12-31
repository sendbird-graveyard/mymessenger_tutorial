//
//  InteageFileLink.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageFileInfo.h"
#import "InteageSender.h"
#import "InteageMessageModel.h"
#import "InteageBlockedUser.h"

/**
 *  Class for file being transfered through messaging. This class includes sender, file information, and message blocked status
 */
@interface InteageFileLink : InteageMessageModel

/**
 *  Message sender. Uses [`InteageSender`](./InteageSender.html) class
 */
@property (retain) InteageSender *sender;

/**
 *  File information. Uses [`InteageFileInfo`](./InteageFileInfo.html) class
 */
@property (retain) InteageFileInfo *fileInfo;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

@property (retain) NSDictionary *jsonObj;

/**
 *  Returns YES if sent by a blocked user, otherwise returns NO
 */
@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

/**
 *  Get the name of the sender
 *
 *  @return User name of the sender
 */
- (NSString *)getSenderName;

- (NSString *) toJson;

@end
