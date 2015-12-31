//
//  InteageUser.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 4. 20..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  User class. Either a new user is created or logged in using an existing user based on the parameters set using [`loginWithUserName:`](./Inteage.html#//api/name/loginWithUserName:), [`loginWithUserName:andUserImageUrl:`](./Inteage.html#//api/name/loginWithUserName:andUserImageUrl:), [`igawLoginWithUserId:`](/Inteage.html#//api/name/igawLoginWithUserId:), [`igawLoginWithUserName:`](./Inteage.html#//api/name/igawLoginWithUserName:), [`igawLoginWithUserName:andUserImageUrl:`](./Inteage.html#//api/name/igawLoginWithUserName:andUserImageUrl:), [`loginWithUserId:andUserName:`](./Inteage.html#//api/name/loginWithUserId:andUserName:) methods. [`guestId`](./InteageUser.html#//api/name/guestId) is used to identify unique users, so we recommending using [`guestId`](./InteageUser.html#//api/name/guestId) to map the app's users to Inteage users.
 */
@interface InteageUser : NSObject

/**
 *  Integer value ID asssigned to users
 */
@property long long userId;

/**
 *  User name
 */
@property (retain) NSString *name;

/**
 *  Profile iamge URL
 */
@property (retain) NSString *imageUrl;

/**
 *  Unique identifier assigned to users
 */
@property (retain) NSString *guestId;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

@end
