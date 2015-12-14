//
//  Channel.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

@interface JiverChannel : JiverMessageModel

@property long long channelId;

@property int memberCount;

@property (retain) NSString *url;

@property (retain) NSString *name;

@property (retain) NSString *coverUrl;

@property long long createdAt;

@property (retain) NSDictionary *jsonObj;
- (id) initWithDic:(NSDictionary *) dic;

- (NSString *) getUrlWithoutAppPrefix;

- (NSString *) toJson;

@end
