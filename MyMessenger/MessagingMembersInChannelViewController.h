//
//  MessagingMembersInChannelViewController.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/11/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

#import "MessagingMemberTableViewCell.h"
#import "MyUtils.h"

@interface MessagingMembersInChannelViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingMemberTableView;

- (void)setJiverMessagingChannel:(JiverMessagingChannel *)channel;

@end
