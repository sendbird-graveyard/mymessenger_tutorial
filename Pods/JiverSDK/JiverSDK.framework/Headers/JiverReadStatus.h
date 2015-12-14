//
//  ReadStatus.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverUser.h"

@interface JiverReadStatus : NSObject

@property (retain) JiverUser *user;

@property long long timestamp;
@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

- (NSString *) getUserId;
- (NSString *) toJson;

@end
