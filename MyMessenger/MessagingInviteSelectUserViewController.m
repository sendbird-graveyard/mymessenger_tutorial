//
//  MessagingInviteSelectUserViewController.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/10/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "MessagingInviteSelectUserViewController.h"

@interface MessagingInviteSelectUserViewController ()<UITableViewDataSource, UITableViewDelegate, MessagingViewControllerDelegate> {
    NSMutableArray *userArray;
    BOOL isLoadingUser;
    JiverMemberListQuery *memberListQuery;
    JiverChannel *selectedChannel;
}

@end

@implementation MessagingInviteSelectUserViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    isLoadingUser = NO;
    
    [self.messagingInviteSelectUserTableView setContentInset:UIEdgeInsetsMake(64, 0, 0, 0)];
    [self.messagingInviteSelectUserTableView setDelegate:self];
    [self.messagingInviteSelectUserTableView setDataSource:self];
    
    userArray = [[NSMutableArray alloc] init];
    
    // See 'How to build an iOS messaging app'
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)setChannel:(JiverChannel *)channel
{
    selectedChannel = channel;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)loadNextMemberList
{
    if (![memberListQuery hasNext]) {
        return;
    }
    
    if (isLoadingUser) {
        return;
    }
    isLoadingUser = YES;
    
    [memberListQuery nextWithResultBlock:^(NSMutableArray *queryResult) {
        for (JiverMember *member in queryResult) {
            [userArray addObject:member];
        }
        [self.messagingInviteSelectUserTableView reloadData];
        isLoadingUser = NO;
    } endBlock:^(NSError *error) {
        
    }];
}

- (IBAction)closeSelectUser:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)inviteUsers:(id)sender {
    // See 'How to build an iOS messaging app'
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [userArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        MessagingInviteSelectUserTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessagingInviteUserCell"];
        JiverMember *member = (JiverMember *)[userArray objectAtIndex:[indexPath row]];
        [cell setJiverMember:member];
        
        if ([indexPath row] + 1 == [userArray count]) {
            [self loadNextMemberList];
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

#pragma mark - MessagingViewControllerDelegate
- (void) prepareCloseMessagingViewController
{

}

@end
