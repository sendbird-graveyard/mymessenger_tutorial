//
//  SystemMessage.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

#define kJiverCategoryNone 0
#define kJiverCategoryChannelJoin 10100
#define kJiverCategoryChannelLeave 10101
#define kJiverCategoryChannelInvite 10102
#define kJiverCategoryTooManyMessages 10200
#define kJiverCategoryMessagingUserBlocked 10300
#define kJiverCategoryMessagingUserDeactivated 10400

@interface JiverSystemMessage : JiverMessageModel

@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

@property long long category;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (NSString *) toJson;

@end
