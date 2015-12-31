//
//  InteageSender.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 6..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class used for sender.
 */
@interface InteageSender : NSObject

/**
 *  Integer number ID assigned to user for identification.
 */
@property long long senderId;

/**
 *  User name
 */
@property (retain) NSString *name;

/**
 *  Profile image URL
 */
@property (retain) NSString *imageUrl;

/**
 *  ID used for identification. Same as [`InteageUser guestID`](./InteageUser.html#//api/name/guestId)
 */
@property (retain) NSString *guestId;

- (id) initWithDic:(NSDictionary *)dic;

@end
