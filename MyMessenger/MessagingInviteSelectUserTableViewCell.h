//
//  MessagingInviteSelectUserTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/10/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <JiverSDK/JiverSDK.h>

@interface MessagingInviteSelectUserTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *nicknameLabel;
@property (weak, nonatomic) IBOutlet UIImageView *profileImageView;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewWidth;

- (void) setJiverMember:(JiverMember *)mbr;

@end
