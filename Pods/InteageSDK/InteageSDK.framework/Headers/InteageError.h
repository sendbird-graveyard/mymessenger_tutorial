//
//  InteageError.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 4. 20..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kErrNetwork 9000
#define kErrDataParsing 9010

#define kErrLogin 10000
#define kErrLoginAccessTokenInvalid 10010
#define kErrGetChannelInfo 11000
#define kErrFileUpload 12000
#define kErrLoadChannel 13000
#define kErrStartMessaging 14000
#define kErrJoinMessaging 14050
#define kErrEndMessaging 14100
#define kErrEndAllMessaging 14110
#define kErrInviteMessaging 14150
#define kErrHideMessaging 14200
#define kErrHideAllMessaging 14210
#define kErrMarkAsRead 15100
#define kErrMarkAsReadAll 15200
#define kErrLeaveChannel 16000

/**
 *  This class defines the error codes. For detailed error codes, please refer to [Inteage iOS SDK](https://inteage.gitbooks.io/ios-sdk/content/en/misc.html).
 */
@interface InteageError : NSObject

@end
