//
//  OpenChatFileMessageTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/7/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <JiverSDK/JiverSDK.h>

@interface OpenChatFileMessageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *nicknameLabel;
@property (weak, nonatomic) IBOutlet UIImageView *fileImageView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *topMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bottomMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *nicknameFileImageGap;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *fileImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *fileImageViewWidth;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *leftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *rightMargin;

- (void)setFileMessage:(JiverFileLink *)msg;
- (CGFloat) getCellHeight;

@end
