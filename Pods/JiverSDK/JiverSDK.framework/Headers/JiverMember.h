//
//  Member.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 5. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverMember : NSObject

@property long long memberId;

@property (retain) NSString *name;

@property (retain) NSString *imageUrl;

@property (retain) NSString *guestId;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *) dic;
- (NSString *) toJson;

@end
