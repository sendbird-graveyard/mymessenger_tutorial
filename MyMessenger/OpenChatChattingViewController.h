//
//  OpenChatChattingViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <InteageSDK/InteageSDK.h>
#import <MobileCoreServices/UTCoreTypes.h>

#import "MyUtils.h"

@interface OpenChatChattingViewController : UIViewController
@property (weak, nonatomic) IBOutlet UITableView *openChatChattingTableView;
@property (weak, nonatomic) IBOutlet UINavigationItem *navigationBarTitle;
@property (weak, nonatomic) IBOutlet UIButton *sendFileButton;
@property (weak, nonatomic) IBOutlet UIButton *sendMessageButton;
@property (weak, nonatomic) IBOutlet UITextField *messageTextField;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputViewBottomMargin;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *prevMessageLoadingIndicator;

- (void)setChannel:(InteageChannel *)ch;

@end
