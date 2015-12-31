//
//  InteageSDKUtils.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 8. 21..
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InteageSDKUtils : NSObject

+ (NSUInteger)occurrenceCountOfCharacter:(UniChar)character inSourceString:(NSString *)source;
+ (NSString *) jsonStringWithPrettyPrint:(BOOL) prettyPrint fromDictionary:(NSDictionary *)dic;

@end
