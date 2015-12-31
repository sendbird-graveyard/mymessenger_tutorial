//
//  MessagingInviteSelectChannelViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/10/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

#import "MessagingInviteChannelTableViewCell.h"
#import "MessagingInviteSelectUserViewController.h"
#import "MyUtils.h"

@protocol MessagingInviteSelectChannelViewControllerDelegate<NSObject>

- (void) prepareCloseMessagingInviteSelectChannelViewController;

@end

@interface MessagingInviteSelectChannelViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *openChatChannelListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *openChatChannelListLoadingIndicator;

@property (nonatomic, weak) id <MessagingInviteSelectChannelViewControllerDelegate> delegate;

@end
