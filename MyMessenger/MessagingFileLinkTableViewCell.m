//
//  MessagingFileLinkTableViewCell.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/9/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "MessagingFileLinkTableViewCell.h"

@implementation MessagingFileLinkTableViewCell {
    InteageFileLink *message;
}

- (void)awakeFromNib {
    // Initialization code
    [self.profileImageView.layer setCornerRadius:self.profileImageHeight.constant / 2];
    [self.profileImageView.layer setBorderColor:[[UIColor grayColor] CGColor]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setFileMessage:(InteageFileLink *)msg
{
    message = msg;
    
    [self.nicknameLabel setAttributedText:[self buildNickname]];
    [self setFileImage:[[message fileInfo] url]];
    long long ts = [message getMessageTimestamp] / 1000;
    [self.dateTimeLabel setText:[MyUtils lastMessageDateTime:ts]];
    [self setProfileImage:[[message sender] imageUrl]];
    
    int unreadCount = 0;
    if (self.readStatus != nil) {
        for (NSString *key in self.readStatus) {
            if (![key isEqualToString:[Inteage getUserId]]) {
                long long readTime = [[self.readStatus objectForKey:key] longLongValue] / 1000;
                if (ts <= readTime) {
                    //                    [self.unreadLabel setHidden:YES];
                }
                else {
                    unreadCount = unreadCount + 1;
                }
            }
        }
    }
    
    if (unreadCount == 0) {
        [self.unreadCountLabel setHidden:YES];
    }
    else {
        [self.unreadCountLabel setHidden:NO];
        [self.unreadCountLabel setText:[NSString stringWithFormat:@"Unread %d", unreadCount]];
    }
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

- (void)setFileImage:(NSString *)imageUrl
{
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Inteage VERSION]] forHTTPHeaderField:@"User-Agent"];
    [request setURL:[NSURL URLWithString:imageUrl]];
    
    [self.fileLinkImageView setImageWithURLRequest:request placeholderImage:nil success:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, UIImage * _Nonnull image) {
        CGSize newSize = CGSizeMake([self.imageViewHeight constant] * 4 , [self.imageViewWidth constant] * 4);
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
        
        [self.fileLinkImageView setImage:newImage];
    } failure:nil];
}

- (void)setProfileImage:(NSString *)imageUrl
{
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Inteage VERSION]] forHTTPHeaderField:@"User-Agent"];
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

- (CGFloat) getCellHeight
{
    NSAttributedString *attributedNickname = [self buildNickname];
    
    CGFloat nicknameWidth = 180.0;
    CGRect nicknameRect = [attributedNickname boundingRectWithSize:CGSizeMake(nicknameWidth, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    
    return 8 + nicknameRect.size.height + self.imageViewHeight.constant + self.messageContainerBottomPadding.constant + self.messageContainerTopPadding.constant + 4;
}

@end
