//
//  InteageBlockedUser.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 11. 4..
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageMessageModel.h"

@interface InteageBlockedUser : InteageMessageModel

- (id) initWithDic:(NSDictionary *)dic;
- (NSString *) toJson;
- (BOOL) isMessageBlocked:(InteageMessageModel *)message;

@property (retain) NSDictionary *jsonObj;
@property (retain) NSDictionary *blockedUserList;

@end
