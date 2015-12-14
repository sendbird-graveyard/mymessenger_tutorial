//
//  SecondViewController.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/4/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingChannelListViewController.h"
#import "MessagingViewController.h"
#import "MessagingEditChannelListViewController.h"
#import "MessagingInviteSelectChannelViewController.h"

@interface MessagingChannelListViewController ()<UITableViewDataSource, UITableViewDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, MessagingViewControllerDelegate, MessagingInviteSelectChannelViewControllerDelegate> {
    NSMutableArray *channelArray;
    BOOL isLoadingChannel;
    JiverMessagingChannelListQuery *messagingChannelListQuery;
}

@end

@implementation MessagingChannelListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self.channelLoadingIndicator setHidden:YES];
    isLoadingChannel = NO;
    
    channelArray = [[NSMutableArray alloc] init];
    
    [self.messagingChannelListTableView setContentInset:UIEdgeInsetsMake(64, 0, 48, 0)];
    [self.messagingChannelListTableView setDelegate:self];
    [self.messagingChannelListTableView setDataSource:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) startJiver
{
    // See 'How to build an iOS messaging app'
}

- (void)loadNextChannelList
{
    // See 'How to build an iOS messaging app'
}

#pragma mark - Navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.destinationViewController isKindOfClass:[MessagingEditChannelListViewController class]]) {
        MessagingEditChannelListViewController *vc = (MessagingEditChannelListViewController *)segue.destinationViewController;
        [vc setDelegate:self];
    }
    else if ([segue.destinationViewController isKindOfClass:[MessagingInviteSelectChannelViewController class]]) {
        MessagingInviteSelectChannelViewController *vc = (MessagingInviteSelectChannelViewController *)segue.destinationViewController;
        [vc setDelegate:self];
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [channelArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        MessagingChannelListTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessagingChannelCell"];
        JiverMessagingChannel *channel = (JiverMessagingChannel *)[channelArray objectAtIndex:[indexPath row]];
        [cell setMessagingChannel:channel];
       
        if ([indexPath row] + 1 == [channelArray count]) {
            [self loadNextChannelList];
        }
        
        return cell;
    }
    else {
        return nil;
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return nil;
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 64;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // See 'How to build an iOS messaging app'
}

#pragma mark - MessagingViewControllerDelegate
- (void) prepareCloseMessagingViewController
{
    [self startJiver];
}

#pragma mark - MessagingInviteSelectChannelViewControllerDelegate
- (void) prepareCloseMessagingInviteSelectChannelViewController
{
    [self startJiver];
}

@end
