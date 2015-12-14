//
//  MessagingSystemMessageTableViewCell.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/6/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingSystemMessageTableViewCell.h"

@implementation MessagingSystemMessageTableViewCell {
    JiverSystemMessage *message;
}

- (void)awakeFromNib {
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setSystemMessage:(JiverSystemMessage *)msg
{
    message = msg;
    
    [self.systemMessageLabel setAttributedText:[self buildMessage]];
}

- (NSAttributedString *) buildMessage
{
    NSString *messageBody = [message message];
    
    NSMutableDictionary *messageBodyAttribute = [NSMutableDictionary dictionaryWithObjectsAndKeys:[UIFont systemFontOfSize:14], NSFontAttributeName, nil];
    
    NSRange messageBodyRange = NSMakeRange(0, [messageBody length]);
    
    NSMutableAttributedString *attributedMessage = [[NSMutableAttributedString alloc] initWithString:messageBody];
    [attributedMessage beginEditing];
    [attributedMessage setAttributes:messageBodyAttribute range:messageBodyRange];
    [attributedMessage endEditing];
    
    return attributedMessage;
}

- (CGFloat) getCellHeight
{
    CGFloat totalWidth = self.contentView.frame.size.width;
    
    NSAttributedString *attributedMessage = [self buildMessage];
    CGFloat messageWidth = totalWidth - ([self.messageRightMargin constant] + [self.messageLeftMargin constant]);
    CGRect messageRect = [attributedMessage boundingRectWithSize:CGSizeMake(messageWidth, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    
    return messageRect.size.height + self.messageTopMargin.constant + self.messageBottomMargin.constant;
}

@end
