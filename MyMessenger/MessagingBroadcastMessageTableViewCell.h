//
//  MessagingBroadcastMessageTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/6/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

@interface MessagingBroadcastMessageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *broadcastMessageLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageTopMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageBottomMargin;

- (void)setBroadcastMessage:(InteageBroadcastMessage *)msg;
- (CGFloat) getCellHeight;

@end
