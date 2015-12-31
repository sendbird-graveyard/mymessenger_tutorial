//
//  MessagingSystemMessageTableViewCell.h
//  MyMessenger
//
//  Created by Inteage Developers on 12/6/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <InteageSDK/InteageSDK.h>

@interface MessagingSystemMessageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *systemMessageLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageTopMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageLeftMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageRightMargin;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *messageBottomMargin;

- (void) setSystemMessage:(InteageSystemMessage *)msg;
- (CGFloat) getCellHeight;

@end
