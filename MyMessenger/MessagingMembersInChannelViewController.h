//
//  MessagingMembersInChannelViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/11/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

#import "MessagingMemberTableViewCell.h"
#import "MyUtils.h"

@interface MessagingMembersInChannelViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingMemberTableView;

- (void)setInteageMessagingChannel:(InteageMessagingChannel *)channel;

@end
