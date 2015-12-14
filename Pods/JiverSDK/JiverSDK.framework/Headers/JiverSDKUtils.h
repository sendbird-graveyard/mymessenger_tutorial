//
//  JiverSDKUtils.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 8. 21..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverSDKUtils : NSObject

+ (NSUInteger)occurrenceCountOfCharacter:(UniChar)character inSourceString:(NSString *)source;
+ (NSString *) jsonStringWithPrettyPrint:(BOOL) prettyPrint fromDictionary:(NSDictionary *)dic;

@end
