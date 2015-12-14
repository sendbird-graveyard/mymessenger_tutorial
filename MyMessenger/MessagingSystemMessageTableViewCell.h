//
//  MessagingSystemMessageTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/6/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

@interface MessagingSystemMessageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *systemMessageLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageTopMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageBottomMargin;

- (void) setSystemMessage:(JiverSystemMessage *)msg;
- (CGFloat) getCellHeight;

@end
