//
//  MessagingInviteSelectUserViewController.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/10/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

#import "MessagingInviteSelectUserTableViewCell.h"
#import "MyUtils.h"
#import "MessagingViewController.h"

@interface MessagingInviteSelectUserViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingInviteSelectUserTableView;

- (void)setChannel:(JiverChannel *)channel;

@end
