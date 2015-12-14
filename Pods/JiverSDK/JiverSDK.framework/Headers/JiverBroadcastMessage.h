//
//  BroadcastMessage.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 10..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

@interface JiverBroadcastMessage : JiverMessageModel

@property (retain) NSString *message;
@property (retain) NSDictionary *jsonObj;

@property (retain) NSString *data;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (NSString *) toJson;

@end
