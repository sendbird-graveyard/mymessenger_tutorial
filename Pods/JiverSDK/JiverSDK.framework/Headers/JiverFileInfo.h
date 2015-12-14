//
//  FileInfo.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 3. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JiverFileInfo : NSObject

@property (retain) NSString *url;

@property (retain) NSString *name;

@property unsigned long size;

@property (retain) NSString *type;

@property (retain) NSString *customField;

- (id) initWithUrl:(NSString *)url name:(NSString *)name type:(NSString *)type size:(unsigned long)size customField:(NSString *)customField;

@end
