//
//  OpenChatBroadcastTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

@interface OpenChatBroadcastTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastTopMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *broadcastBottomMargin;
@property (weak, nonatomic) IBOutlet UILabel *broadcastLabel;

- (void)setBroadcastMessage:(JiverBroadcastMessage *)msg;
- (CGFloat) getCellHeight;

@end
