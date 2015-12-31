//
//  MessagingEditChannelListViewController.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/12/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "MessagingEditChannelListViewController.h"

@interface MessagingEditChannelListViewController ()<UITableViewDataSource, UITableViewDelegate> {
    NSMutableArray *channelArray;
    BOOL isLoadingChannel;
    InteageMessagingChannelListQuery *messagingChannelListQuery;
}

@end

@implementation MessagingEditChannelListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    channelArray = [[NSMutableArray alloc] init];
    
    [self.channelLoadingIndicator setHidden:YES];
    isLoadingChannel = NO;
    
    channelArray = [[NSMutableArray alloc] init];
    
    [self.messagingChannelListTableView setContentInset:UIEdgeInsetsMake(64, 0, 0, 0)];
    [self.messagingChannelListTableView setDelegate:self];
    [self.messagingChannelListTableView setDataSource:self];
    
    [Inteage loginWithUserId:[Inteage deviceUniqueID] andUserName:[MyUtils getUserName] andUserImageUrl:[MyUtils getUserProfileImage] andAccessToken:@""];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        messagingChannelListQuery = [Inteage queryMessagingChannelList];
        [messagingChannelListQuery setLimit:15];
        if ([messagingChannelListQuery hasNext]) {
            [messagingChannelListQuery nextWithResultBlock:^(NSMutableArray *queryResult) {
                [channelArray removeAllObjects];
                [channelArray addObjectsFromArray:queryResult];
                [self.messagingChannelListTableView reloadData];
            } endBlock:^(NSInteger code) {
                
            }];
        }
    });
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)closeEditMessagingChannelViewController:(id)sender {
    [[self delegate] prepareCloseMessagingViewController];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)hideMessagingChannel:(id)sender {   
    NSIndexPath *selectedIndexPath = [self.messagingChannelListTableView indexPathForSelectedRow];
    if (selectedIndexPath != nil) {
        [Inteage hideMessagingWithChannelUrl:[[channelArray objectAtIndex:selectedIndexPath.row] getUrl]];
        messagingChannelListQuery = [Inteage queryMessagingChannelList];
        [[self delegate] prepareCloseMessagingViewController];
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}

- (IBAction)leaveMessagingChannel:(id)sender {
    NSIndexPath *selectedIndexPath = [self.messagingChannelListTableView indexPathForSelectedRow];
    if (selectedIndexPath != nil) {
        [Inteage endMessagingWithChannelUrl:[[channelArray objectAtIndex:selectedIndexPath.row] getUrl]];
        [[self delegate] prepareCloseMessagingViewController];
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}

- (void)loadNextChannelList
{
    if (isLoadingChannel) {
        return;
    }
    isLoadingChannel = YES;
    
    if ([messagingChannelListQuery hasNext]) {
        [messagingChannelListQuery nextWithResultBlock:^(NSMutableArray *queryResult) {
            [channelArray addObjectsFromArray:queryResult];
            [self.messagingChannelListTableView reloadData];
            
            isLoadingChannel = NO;
        } endBlock:^(NSInteger code) {
            isLoadingChannel = NO;
        }];
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [channelArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        MessagingEditListTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessagingChannelCell"];
        InteageMessagingChannel *channel = (InteageMessagingChannel *)[channelArray objectAtIndex:[indexPath row]];
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
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    
    cell.accessoryType = UITableViewCellAccessoryCheckmark;
}

- (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    
    cell.accessoryType = UITableViewCellAccessoryNone;
}

@end
