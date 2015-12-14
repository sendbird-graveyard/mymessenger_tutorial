//
//  JiverBlockedUser.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 11. 4..
//  Copyright © 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

@interface JiverBlockedUser : JiverMessageModel

- (id) initWithDic:(NSDictionary *)dic;
- (NSString *) toJson;
- (BOOL) isMessageBlocked:(JiverMessageModel *)message;

@property (retain) NSDictionary *jsonObj;
@property (retain) NSDictionary *blockedUserList;

@end
