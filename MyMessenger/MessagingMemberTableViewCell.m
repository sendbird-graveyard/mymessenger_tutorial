//
//  MessagingMemberTableViewCell.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/11/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "MessagingMemberTableViewCell.h"

@implementation MessagingMemberTableViewCell {
    InteageMemberInMessagingChannel *member;
}

- (void)awakeFromNib {
    // Initialization code
    
    self.profileImageView.layer.cornerRadius = self.profileImageViewHeight.constant / 2;
    [self.profileImageView.layer setBorderColor:[[UIColor grayColor] CGColor]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void) setInteageMember:(InteageMemberInMessagingChannel *)mbr
{
    member = mbr;
    
    [self setProfileImage:[member imageUrl]];
    [self setNickname:[member name]];
}

- (void)setProfileImage:(NSString *)imageUrl
{
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Inteage VERSION]] forHTTPHeaderField:@"User-Agent"];
    [request setURL:[NSURL URLWithString:imageUrl]];
    
    [self.profileImageView setImageWithURLRequest:request placeholderImage:nil success:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, UIImage * _Nonnull image) {
        CGSize newSize = CGSizeMake([self.profileImageViewHeight constant] * 4 , [self.profileImageViewWidth constant] * 4);
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

- (void)setNickname:(NSString *)nickname
{
    [self.nicknameLabel setText:nickname];
}

@end
