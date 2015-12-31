//
//  InteageFileInfo.h
//  InteageFramework
//
//  Created by Inteage Developers on 2015. 3. 3. in San Francisco, CA.
//  Copyright (c) 2015 INTEAGE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class used for file information, which includes file URL, file name, file size, file type, and custom field. This class is included in [`InteageFileLink`](./InteageFileLink.html).
 */
@interface InteageFileInfo : NSObject

/**
 *  File URL
 */
@property (retain) NSString *url;

/**
 *  File name
 */
@property (retain) NSString *name;

/**
 *  File size
 */
@property unsigned long size;

/**
 *  File type
 */
@property (retain) NSString *type;

/**
 *  Custom field
 */
@property (retain) NSString *customField;

/**
 *  Initialize `InteageFileInfo` object.
 *
 *  @param url         File URL
 *  @param name        File name
 *  @param type        File type
 *  @param size        File size
 *  @param customField Custom field
 *
 *  @return `InteageFileInfo` instance.
 */
- (id) initWithUrl:(NSString *)url name:(NSString *)name type:(NSString *)type size:(unsigned long)size customField:(NSString *)customField;

@end
