//
//  JiverMention.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 7. 30..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverSender.h"

@interface JiverMention : NSObject

@property (retain) NSString *channelUrl;

@property (retain) NSString *channelType;

@property (retain) NSString *message;

@property (retain) JiverSender *sender;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *) dic;

- (NSString *) toJson;

- (NSString *) getSenderName;

- (NSString *) getSenderImageUrl;

@end
