//
//  MessageOpponentFileLinkTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/9/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <InteageSDK/InteageSDK.h>

#import "MyUtils.h"


@interface MessageOpponentFileLinkTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *profileImageView;
@property (weak, nonatomic) IBOutlet UIImageView *fileLinkImageView;
@property (weak, nonatomic) IBOutlet UILabel *nicknameLabel;
@property (weak, nonatomic) IBOutlet UILabel *dateTimeLabel;
@property (weak, nonatomic) IBOutlet UILabel *unreadCountLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewWidth;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *fileLinkImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *fileLinkImageViewWidth;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageContainerViewBottomPadding;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageContainerViewTopPadding;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewBottomMargin;

- (void)setFileMessage:(InteageFileLink *)msg;
- (CGFloat) getCellHeight;

@end
