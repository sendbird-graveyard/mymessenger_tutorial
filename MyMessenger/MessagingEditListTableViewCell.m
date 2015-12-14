//
//  MessagingEditListTableViewCell.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/12/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingEditListTableViewCell.h"

@implementation MessagingEditListTableViewCell {
    JiverMessagingChannel *channel;
}

- (void)awakeFromNib {
    // Initialization code
    
    self.messagingChannelCoverImageView.layer.cornerRadius = self.messagingChannelCoverImageWidth.constant / 2;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

- (void)setCoverImage:(NSString *)imageUrl
{
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Jiver VERSION]] forHTTPHeaderField:@"User-Agent"];
    [request setURL:[NSURL URLWithString:imageUrl]];
    
    [self.messagingChannelCoverImageView setImageWithURLRequest:request placeholderImage:nil success:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, UIImage * _Nonnull image) {
        CGSize newSize = CGSizeMake([self.messagingChannelCoverImageHeight constant] * 4 , [self.messagingChannelCoverImageWidth constant] * 4);
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
        
        [self.messagingChannelCoverImageView setImage:newImage];
    } failure:nil];
}

- (void)setMessagingChannel:(JiverMessagingChannel *)mc
{
    channel = mc;
    
    [self.messagingChannelTopicLabel setText:[MyUtils generateMessagingChannelTitle:channel]];
    
    [self setCoverImage:[[channel channel] coverUrl]];
}

@end
