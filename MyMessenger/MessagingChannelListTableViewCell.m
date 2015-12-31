//
//  MessagingChannelListTableViewCell.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/6/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "MessagingChannelListTableViewCell.h"

@implementation MessagingChannelListTableViewCell {
    InteageMessagingChannel *channel;
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
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Inteage VERSION]] forHTTPHeaderField:@"User-Agent"];
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

- (void)setMessagingChannel:(InteageMessagingChannel *)mc
{
    channel = mc;
    
    [self.messagingChannelTopicLabel setText:[MyUtils generateMessagingChannelTitle:channel]];
    [self.lastMessageLabel setText:[[channel lastMessage] message]];
    long long ts = [[channel lastMessage] getMessageTimestamp] / 1000;
    [self.lastMessageDateLabel setText:[MyUtils lastMessageDateTime:ts]];
    [self.memberCountLabel setText:[NSString stringWithFormat:@"%lu", [[channel members] count]]];
    
    [self setCoverImage:[[channel channel] coverUrl]];
    
    // Count > 0, show count
    int count = [channel unreadMessageCount];
    if (count > 0) {
        
        // Create label
        CGFloat fontSize = 14;
        UILabel *label = [[UILabel alloc] init];
        label.font = [UIFont systemFontOfSize:fontSize];
        label.textAlignment = NSTextAlignmentCenter;
        label.textColor = [UIColor whiteColor];
        label.backgroundColor = [UIColor redColor];
        
        // Add count to label and size to fit
        label.text = [NSString stringWithFormat:@"%@", @(count)];
        [label sizeToFit];
        
        // Adjust frame to be square for single digits or elliptical for numbers > 9
        CGRect frame = label.frame;
        frame.size.height += (int)(0.4*fontSize);
        frame.size.width = (count <= 9) ? frame.size.height : frame.size.width + (int)fontSize;
        label.frame = frame;
        
        // Set radius and clip to bounds
        label.layer.cornerRadius = frame.size.height/2.0;
        label.clipsToBounds = true;
        
        // Show label in accessory view and remove disclosure
        self.accessoryView = label;
        self.accessoryType = UITableViewCellAccessoryNone;
    }
    else {
        self.accessoryView = nil;
        self.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
}

@end
