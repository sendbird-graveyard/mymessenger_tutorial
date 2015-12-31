//
//  MessagingInviteSelectUserViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/10/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

#import "MessagingInviteSelectUserTableViewCell.h"
#import "MyUtils.h"
#import "MessagingViewController.h"

@interface MessagingInviteSelectUserViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingInviteSelectUserTableView;

- (void)setChannel:(InteageChannel *)channel;

@end
