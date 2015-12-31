//
//  MessagingInviteChannelTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/10/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <InteageSDK/InteageSDK.h>

@interface MessagingInviteChannelTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *channelTopicLabel;
@property (weak, nonatomic) IBOutlet UIImageView *channelCoverImageView;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *channelCoverImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *channelCoverImageViewWidth;

- (void)setChannel:(InteageChannel *)ch;

@end
