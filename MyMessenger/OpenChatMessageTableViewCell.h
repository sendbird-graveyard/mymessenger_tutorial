//
//  OpenChatMessageTableViewCell.h
//  MyMessenger
//
//  Created by Jed Kyung on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JiverSDK/JiverSDK.h>

@interface OpenChatMessageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *messageLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLabelLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLabelRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLabelBottomMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLabelTopMargin;

- (void)setMessage:(JiverMessage *)msg;
- (CGFloat)getCellHeight;

@end
