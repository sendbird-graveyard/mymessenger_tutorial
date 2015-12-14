//
//  JiverStructuredMessage.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 10. 14..
//  Copyright © 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverSender.h"
#import "JiverMessageModel.h"
//#import "JiverSDKUtils.h"

@interface JiverStructuredMessage : JiverMessageModel

@property (retain) NSString *message;
@property (retain) JiverSender *sender;
//@property BOOL isOpMessage;
//@property BOOL isGuestMessage;
@property (retain) NSString *data;
@property (retain) NSDictionary *jsonObj;
@property (retain) NSString *tempId;
@property (retain) NSDictionary *structuredMessage;

@property (retain) NSString *structuredMessageTitle;
@property (retain) NSString *structuredMessageDesc;
@property (retain) NSString *structuredMessageThumbUrl;
@property (retain) NSString *structuredMessageUrl;
@property (retain) NSString *structuredMessageName;
@property (retain) NSString *structuredMessageIconUrl;

- (id) initWithDic:(NSDictionary *)dic;
- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (BOOL) hasSameSender:(JiverStructuredMessage *)msg;
- (NSString *)getSenderName;
//- (void) mergeWith:(JiverMessage *)merge;
- (NSString *) toJson;

@end
