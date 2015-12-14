//
//  MessagingInviteSelectChannelViewController.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/10/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingInviteSelectChannelViewController.h"

@interface MessagingInviteSelectChannelViewController ()<UITableViewDataSource, UITableViewDelegate> {
    NSMutableArray *channelArray;
    BOOL isLoadingChannel;
    JiverChannelListQuery *channelListQuery;
}

@end

@implementation MessagingInviteSelectChannelViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    isLoadingChannel = NO;
    
    [self.openChatChannelListTableView setContentInset:UIEdgeInsetsMake(64, 0, 0, 0)];
    [self.openChatChannelListTableView setDelegate:self];
    [self.openChatChannelListTableView setDataSource:self];
    
    channelArray = [[NSMutableArray alloc] init];
    
    [self.openChatChannelListLoadingIndicator setHidden:YES];

    [Jiver loginWithUserId:[Jiver deviceUniqueID] andUserName:[MyUtils getUserName] andUserImageUrl:[MyUtils getUserProfileImage] andAccessToken:@""];
    channelListQuery = [Jiver queryChannelList];
    [channelListQuery nextWithResultBlock:^(NSMutableArray *queryResult) {
        for (JiverChannel *channel in queryResult) {
            [channelArray addObject:channel];
        }
        [self.openChatChannelListTableView reloadData];
    } endBlock:^(NSError *error) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)closeSelectChannel:(id)sender {
    [self.delegate prepareCloseMessagingInviteSelectChannelViewController];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.destinationViewController isKindOfClass:[MessagingInviteSelectUserViewController class]]) {
        NSIndexPath *path = [self.openChatChannelListTableView indexPathForSelectedRow];
        MessagingInviteSelectUserViewController *vc = (MessagingInviteSelectUserViewController *)segue.destinationViewController;
        JiverChannel *channel = [channelArray objectAtIndex:[path row]];
        [vc setChannel:channel];
        
        [self.openChatChannelListTableView deselectRowAtIndexPath:path animated:NO];
    }
}

- (void)loadNextChannelList
{
    if (![channelListQuery hasNext]) {
        return;
    }
    
    if (isLoadingChannel) {
        return;
    }
    isLoadingChannel = YES;
    
    [channelListQuery nextWithResultBlock:^(NSMutableArray *queryResult) {
        for (JiverChannel *channel in queryResult) {
            [channelArray addObject:channel];
        }
        [self.openChatChannelListTableView reloadData];
        isLoadingChannel = NO;
    } endBlock:^(NSError *error) {
        
    }];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [channelArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        MessagingInviteChannelTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessagingInviteChannelCell"];
        JiverChannel *channel = (JiverChannel *)[channelArray objectAtIndex:[indexPath row]];
        [cell setChannel:channel];
        
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

@end
