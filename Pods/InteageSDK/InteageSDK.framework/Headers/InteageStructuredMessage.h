//
//  InteageStructuredMessage.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 10. 14..
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InteageSender.h"
#import "InteageMessageModel.h"
//#import "InteageSDKUtils.h"

@interface InteageStructuredMessage : InteageMessageModel

@property (retain) NSString *message;
@property (retain) InteageSender *sender;
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
- (BOOL) hasSameSender:(InteageStructuredMessage *)msg;
- (NSString *)getSenderName;
//- (void) mergeWith:(InteageMessage *)merge;
- (NSString *) toJson;

@end
