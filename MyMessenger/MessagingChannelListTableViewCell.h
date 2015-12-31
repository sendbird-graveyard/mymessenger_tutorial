//
//  MessagingChannelListTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/6/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <InteageSDK/InteageSDK.h>

#import "MyUtils.h"

@interface MessagingChannelListTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UIImageView *messagingChannelCoverImageView;
@property (weak, nonatomic) IBOutlet UILabel *messagingChannelTopicLabel;
@property (weak, nonatomic) IBOutlet UILabel *lastMessageLabel;
@property (weak, nonatomic) IBOutlet UILabel *lastMessageDateLabel;
@property (weak, nonatomic) IBOutlet UILabel *memberCountLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messagingChannelCoverImageWidth;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messagingChannelCoverImageHeight;

- (void)setMessagingChannel:(InteageMessagingChannel *)mc;

@end
