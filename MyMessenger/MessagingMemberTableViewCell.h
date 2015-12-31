//
//  MessagingMemberTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/11/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <InteageSDK/InteageSDK.h>

#import "MyUtils.h"

@interface MessagingMemberTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *profileImageView;
@property (weak, nonatomic) IBOutlet UILabel *nicknameLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *profileImageViewWidth;

- (void) setInteageMember:(InteageMemberInMessagingChannel *)mbr;

@end
