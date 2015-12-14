//
//  SecondViewController.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <JiverSDK/JiverSDK.h>

#import "MessagingChannelListTableViewCell.h"

@interface MessagingChannelListViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingChannelListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *channelLoadingIndicator;

- (void) startJiver;

@end

