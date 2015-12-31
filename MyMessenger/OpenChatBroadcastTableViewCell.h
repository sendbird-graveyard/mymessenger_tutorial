//
//  OpenChatBroadcastTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

@interface OpenChatBroadcastTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastTopMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastBottomMargin;
@property (weak, nonatomic) IBOutlet UILabel *broadcastLabel;

- (void)setBroadcastMessage:(InteageBroadcastMessage *)msg;
- (CGFloat) getCellHeight;

@end
