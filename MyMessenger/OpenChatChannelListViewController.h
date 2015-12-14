//
//  OpenChatChannelListViewController.h
//  MyMessenger
//
//  Created by Jed Gyeong on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

#import "OpenChatChannelListTableViewCell.h"
#import "OpenChatChattingViewController.h"
#import "MyUtils.h"

@interface OpenChatChannelListViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *openChatChannelListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *openChatChannelListLoadingIndicator;
@property (weak, nonatomic) IBOutlet UISearchBar *channelSearchBar;

@end

