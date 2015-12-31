//
//  FirstViewController.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "OpenChatChannelListViewController.h"

@interface OpenChatChannelListViewController ()<UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate> {
    NSMutableArray *channelArray;
    BOOL isLoadingChannel;
    // See 'How to build an iOS messaging app'
}

@end

@implementation OpenChatChannelListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    isLoadingChannel = NO;
    
    [self.openChatChannelListTableView setContentInset:UIEdgeInsetsMake(108, 0, 48, 0)];
    [self.openChatChannelListTableView setDelegate:self];
    [self.openChatChannelListTableView setDataSource:self];
    
    [self.channelSearchBar setDelegate:self];
    
    channelArray = [[NSMutableArray alloc] init];
    
    [self.openChatChannelListLoadingIndicator setHidden:YES];

    // See 'How to build an iOS messaging app'
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.destinationViewController isKindOfClass:[OpenChatChattingViewController class]]) {
        NSIndexPath *path = [self.openChatChannelListTableView indexPathForSelectedRow];
        OpenChatChattingViewController *vc = (OpenChatChattingViewController *)segue.destinationViewController;
        InteageChannel *channel = [channelArray objectAtIndex:[path row]];
        [vc setChannel:channel];
        
        [self.openChatChannelListTableView deselectRowAtIndexPath:path animated:NO];
    }
}

- (void)loadNextChannelList
{
    // See 'How to build an iOS messaging app'
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [channelArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        OpenChatChannelListTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatChannelListCell"];
        InteageChannel *channel = (InteageChannel *)[channelArray objectAtIndex:[indexPath row]];
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

#pragma mark - UISearchBarDelegate
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar
{
    // See 'How to build an iOS messaging app'
}

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar
{
    // See 'How to build an iOS messaging app'
}

@end
