//
//  SecondViewController.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <AFNetworking/UIImageView+AFNetworking.h>
#import <InteageSDK/InteageSDK.h>

#import "MessagingChannelListTableViewCell.h"

@interface MessagingChannelListViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *messagingChannelListTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *channelLoadingIndicator;

- (void) startInteage;

@end

