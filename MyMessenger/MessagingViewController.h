//
//  MessagingViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/5/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>
#import <QuartzCore/QuartzCore.h>
#import <MobileCoreServices/UTCoreTypes.h>

#import "MyUtils.h"
#import "MessagingMembersInChannelViewController.h"
#import "MessagingInviteSelectChannelViewController.h"

@protocol MessagingViewControllerDelegate<NSObject>

- (void) prepareCloseMessagingViewController;

@end

@interface MessagingViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingTableView;
@property (weak, nonatomic) IBOutlet UIButton *sendFileButton;
@property (weak, nonatomic) IBOutlet UIButton *sendMessageButton;
@property (weak, nonatomic) IBOutlet UITextField *messageTextField;
@property (weak, nonatomic) IBOutlet UINavigationItem *navigationBarTitle;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputViewBottomMargin;
@property (weak, nonatomic) IBOutlet UIView *typingIndicatorView;
@property (weak, nonatomic) IBOutlet UILabel *typeStatusLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *typingIndicatorHeight;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *prevMessageLoadingIndicator;

@property (nonatomic, weak) id <MessagingViewControllerDelegate> delegate;

- (void)setMessagingChannel:(InteageMessagingChannel *)ch;

@end
