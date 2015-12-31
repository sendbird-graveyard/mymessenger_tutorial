//
//  OpenChatChannelListViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

#import "OpenChatChannelListTableViewCell.h"
#import "OpenChatChattingViewController.h"
#import "MyUtils.h"

@interface OpenChatChannelListViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *openChatChannelListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *openChatChannelListLoadingIndicator;
@property (weak, nonatomic) IBOutlet UISearchBar *channelSearchBar;

@end

