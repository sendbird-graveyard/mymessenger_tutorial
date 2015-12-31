//
//  OpenChatMessageTableViewCell.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "OpenChatMessageTableViewCell.h"

@implementation OpenChatMessageTableViewCell {
    InteageMessage *message;
}

- (void)awakeFromNib {
    // Initialization code
    
    [self.messageLabel sizeToFit];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setMessage:(InteageMessage *)msg {
    message = msg;
    
    [self.messageLabel setAttributedText:[self buildMessage]];
}

- (NSAttributedString *) buildMessage
{
    NSString *userName = [message getSenderName];
    NSString *messageBody = [message message];
    
    NSString *fullMessage = [NSString stringWithFormat:@"%@: %@", userName, messageBody];
    
    NSMutableDictionary *userNameAttribute = [NSMutableDictionary dictionaryWithObjectsAndKeys:[UIFont boldSystemFontOfSize:14], NSFontAttributeName, nil];
    NSMutableDictionary *messageBodyAttribute = [NSMutableDictionary dictionaryWithObjectsAndKeys:[UIFont systemFontOfSize:14], NSFontAttributeName, nil];
    
    NSRange userNameRange = NSMakeRange(0, [userName length]);
    NSRange messageBodyRange = NSMakeRange([userName length] + 2, [messageBody length]);
    
    NSMutableAttributedString *attributedMessage = [[NSMutableAttributedString alloc] initWithString:fullMessage];
    [attributedMessage beginEditing];
    [attributedMessage setAttributes:userNameAttribute range:userNameRange];
    [attributedMessage setAttributes:messageBodyAttribute range:messageBodyRange];
    [attributedMessage endEditing];
    
    return attributedMessage;
}

- (CGFloat) getCellHeight
{
    CGFloat totalWidth = self.contentView.frame.size.width;
    
    NSAttributedString *attributedMessage = [self buildMessage];
    CGFloat messageWidth = totalWidth - ([self.messageLabelRightMargin constant] + [self.messageLabelLeftMargin constant]);
    CGRect messageRect = [attributedMessage boundingRectWithSize:CGSizeMake(messageWidth, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    
    return messageRect.size.height + self.messageLabelTopMargin.constant + self.messageLabelBottomMargin.constant + 1;
}

@end
