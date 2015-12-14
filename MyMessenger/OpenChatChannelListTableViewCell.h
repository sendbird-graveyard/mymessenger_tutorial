//
//  OpenChatChannelListTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <JiverSDK/JiverSDK.h>

@interface OpenChatChannelListTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *channelCoverImageView;
@property (weak, nonatomic) IBOutlet UILabel *channelTopicLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *channelCoverImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *channelCoverImageViewWidth;

- (void)setChannel:(JiverChannel *)ch;

@end
