//
//  Sender.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 6..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverSender : NSObject

@property long long senderId;

@property (retain) NSString *name;

@property (retain) NSString *imageUrl;

@property (retain) NSString *guestId;

- (id) initWithDic:(NSDictionary *)dic;

@end
