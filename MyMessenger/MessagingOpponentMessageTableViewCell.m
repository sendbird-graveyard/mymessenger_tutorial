//
//  MessagingOpponentMessageTableViewCell.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/9/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingOpponentMessageTableViewCell.h"

@implementation MessagingOpponentMessageTableViewCell{
    JiverMessage *message;
}

- (void)awakeFromNib {
    // Initialization code
    [self.messageLabel sizeToFit];
    [self.profileImageView.layer setCornerRadius:self.profileImageHeight.constant / 2];
    [self.profileImageView.layer setBorderColor:[[UIColor grayColor] CGColor]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setMessage:(JiverMessage *)msg
{
    message = msg;
    
    [self.nicknameLabel setAttributedText:[self buildNickname]];
    [self.messageLabel setAttributedText:[self buildMessage]];
    long long ts = [message getMessageTimestamp] / 1000;
    [self.dateTimeLabel setText:[MyUtils lastMessageDateTime:ts]];
    [self setProfileImage:[[message sender] imageUrl]];
}

- (void)setProfileImage:(NSString *)imageUrl
{
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Jiver VERSION]] forHTTPHeaderField:@"User-Agent"];
    [request setURL:[NSURL URLWithString:imageUrl]];
    
    [self.profileImageView setImageWithURLRequest:request placeholderImage:nil success:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, UIImage * _Nonnull image) {
        CGSize newSize = CGSizeMake([self.profileImageHeight constant] * 4 , [self.profileImageWidth constant] * 4);
        float widthRatio = newSize.width/image.size.width;
        float heightRatio = newSize.height/image.size.height;
        
        if(widthRatio > heightRatio) {
            newSize=CGSizeMake(image.size.width*heightRatio,image.size.height*heightRatio);
        }
        else {
            newSize=CGSizeMake(image.size.width*widthRatio,image.size.height*widthRatio);
        }
        
        UIGraphicsBeginImageContextWithOptions(newSize, NO, 0.0);
        [image drawInRect:CGRectMake(0,0,newSize.width,newSize.height)];
        UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        
        [self.profileImageView setImage:newImage];
    } failure:nil];
}

- (NSAttributedString *) buildNickname
{
    NSString *userName = [message getSenderName];
    NSMutableDictionary *userNameAttribute = [NSMutableDictionary dictionaryWithObjectsAndKeys:[UIFont boldSystemFontOfSize:10], NSFontAttributeName, nil];
    NSRange userNameRange = NSMakeRange(0, [userName length]);
    NSMutableAttributedString *attributedNickname = [[NSMutableAttributedString alloc] initWithString:userName];
    
    [attributedNickname beginEditing];
    [attributedNickname setAttributes:userNameAttribute range:userNameRange];
    [attributedNickname endEditing];
    
    return attributedNickname;
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
    NSAttributedString *attributedMessage = [self buildMessage];
    NSAttributedString *attributedNickname = [self buildNickname];
    
    CGFloat nicknameWidth = 180.0;
    CGRect nicknameRect = [attributedNickname boundingRectWithSize:CGSizeMake(nicknameWidth, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    
    CGFloat messageWidth = 180.0;
    CGRect messageRect = [attributedMessage boundingRectWithSize:CGSizeMake(messageWidth, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    
    return 8 + nicknameRect.size.height + messageRect.size.height + self.messageLabelBottomMargin.constant + self.messageLabelTopMargin.constant + self.nicknameMessageContainerGap.constant + 4;
}

@end
