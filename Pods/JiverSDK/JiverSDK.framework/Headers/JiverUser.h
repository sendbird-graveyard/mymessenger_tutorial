//
//  User.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverUser : NSObject

@property long long userId;

@property (retain) NSString *name;

@property (retain) NSString *imageUrl;

@property (retain) NSString *guestId;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

@end
