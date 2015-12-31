//
//  OpenChatChattingViewController.m
//  MyMessenger
//
//  Created by Inteage Developers on 12/4/15.
//  Copyright © 2015 INTEAGE.COM. All rights reserved.
//

#import "OpenChatChattingViewController.h"
#import "OpenChatMessageTableViewCell.h"
#import "OpenChatBroadcastTableViewCell.h"
#import "MessagingViewController.h"
#import "OpenChatFileMessageTableViewCell.h"

@interface OpenChatChattingViewController ()<UITableViewDataSource, UITableViewDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, MessagingViewControllerDelegate, UITextFieldDelegate>  {
    InteageChannel *currentChannel;
    NSMutableArray *messages;
    BOOL isLoadingMessage;
    BOOL openImagePicker;
    long long lastMessageTimestamp;
    long long firstMessageTimestamp;
    BOOL scrollLocked;
}

@end

@implementation OpenChatChattingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillShow:)
                                                 name:UIKeyboardWillShowNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillHide:)
                                                 name:UIKeyboardWillHideNotification
                                               object:nil];
    
    openImagePicker = NO;
    isLoadingMessage = NO;
    lastMessageTimestamp = LLONG_MIN;
    firstMessageTimestamp = LLONG_MAX;
    scrollLocked = NO;
    
    messages = [[NSMutableArray alloc] init];
    
    [self.navigationBarTitle setTitle:[currentChannel name]];
    [self.sendFileButton.layer setBorderColor:[[UIColor blueColor] CGColor]];
    [self.sendMessageButton.layer setBorderColor:[[UIColor blueColor] CGColor]];
    [self.messageTextField.layer setBorderColor:[[UIColor blueColor] CGColor]];
    
    [self.messageTextField setDelegate:self];
    
    [self.openChatChattingTableView setDelegate:self];
    [self.openChatChattingTableView setDataSource:self];
    [self.openChatChattingTableView setSeparatorColor:[UIColor clearColor]];
    
    [self.prevMessageLoadingIndicator setHidden:YES];
    
    // See 'How to build an iOS messaging app'
}

- (void)startChattingWithPreviousMessage:(BOOL)tf
{
    // See 'How to build an iOS messaging app'
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [[self navigationController] setNavigationBarHidden:YES animated:NO];
    if (!openImagePicker) {
        [Inteage disconnect];
    }
}

- (void)setChannel:(InteageChannel *)ch {
    currentChannel = ch;
}

- (IBAction)leaveChannel:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)keyboardWillShow:(NSNotification*)notif
{
    NSDictionary *keyboardInfo = [notif userInfo];
    NSValue *keyboardFrameEnd = [keyboardInfo valueForKey:UIKeyboardFrameEndUserInfoKey];
    CGRect keyboardFrameEndRect = [keyboardFrameEnd CGRectValue];
    [self.inputViewBottomMargin setConstant:keyboardFrameEndRect.size.height];
    [self.view updateConstraints];
    
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self scrollToBottomWithReloading:NO animated:NO];
    });
}

- (void)keyboardWillHide:(NSNotification*)notification
{
    [self.inputViewBottomMargin setConstant:0];
    [self.view updateConstraints];
    [self scrollToBottomWithReloading:NO animated:NO];
}

- (void)scrollToBottomWithReloading:(BOOL)reload animated:(BOOL)animated
{
    if (reload) {
        [self.openChatChattingTableView reloadData];
    }
    
    if (scrollLocked) {
        return;
    }
    
    unsigned long msgCount = [messages count];
    if (msgCount > 0) {
        [self.openChatChattingTableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:(msgCount - 1) inSection:0] atScrollPosition:UITableViewScrollPositionBottom animated:animated];
    }
}

- (void) loadPreviousMessages {
    // See 'How to build an iOS messaging app'
}

- (IBAction)clickSendFileButton:(id)sender {
    UIImagePickerController *mediaUI = [[UIImagePickerController alloc] init];
    mediaUI.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    NSMutableArray *mediaTypes = [[NSMutableArray alloc] initWithObjects:(NSString *)kUTTypeImage, nil];
    mediaUI.mediaTypes = mediaTypes;
    [mediaUI setDelegate:self];
    openImagePicker = YES;
    [self presentViewController:mediaUI animated:YES completion:nil];
}

- (void) sendMessage
{
    // See 'How to build an iOS messaging app'
}

- (IBAction)clickSendMessageButton:(id)sender {
    [self sendMessage];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [self sendMessage];
    
    return YES;
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
    return [messages count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        UITableViewCell *commonCell = nil;
        InteageMessageModel *msgModel = (InteageMessageModel *)[messages objectAtIndex:[indexPath row]];
        
        if ([msgModel isKindOfClass:[InteageMessage class]]) {
            OpenChatMessageTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatMessageCell"];
           
            [cell setMessage:(InteageMessage *)msgModel];
            
            commonCell = cell;
        }
        else if ([msgModel isKindOfClass:[InteageBroadcastMessage class]]) {
            OpenChatBroadcastTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatBroadcastCell"];
            [cell setBroadcastMessage:(InteageBroadcastMessage *)msgModel];
            commonCell = cell;
        }
        else if ([msgModel isKindOfClass:[InteageFileLink class]]) {
            OpenChatFileMessageTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatFileCell"];
            [cell setFileMessage:(InteageFileLink *)msgModel];
            commonCell = cell;
        }
        
        if ([indexPath row] == 0) {
            [self loadPreviousMessages];
        }
        
        if ([indexPath row] == [messages count] - 1) {
            scrollLocked = NO;
        }
        
        [commonCell setNeedsLayout];
        
        return commonCell;
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

- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == [messages count] - 1) {
        scrollLocked = YES;
    }
}

- (void) scrollViewDidScroll:(UIScrollView *)scrollView
{
    scrollLocked  = YES;
    [self.view endEditing:YES];
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 0) {
        CGFloat height = 0;
        InteageMessageModel *msgModel = (InteageMessageModel *)[messages objectAtIndex:[indexPath row]];
        
        if ([msgModel isKindOfClass:[InteageMessage class]]) {
            OpenChatMessageTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatMessageCell"];
            
            [cell setMessage:(InteageMessage *)msgModel];
            height = [cell getCellHeight];
        }
        else if ([msgModel isKindOfClass:[InteageBroadcastMessage class]]) {
            OpenChatBroadcastTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatBroadcastCell"];
            [cell setBroadcastMessage:(InteageBroadcastMessage *)msgModel];
            height = [cell getCellHeight];
        }
        else if ([msgModel isKindOfClass:[InteageFileLink class]]) {
            OpenChatFileMessageTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"OpenChatFileCell"];
            [cell setFileMessage:(InteageFileLink *)msgModel];
            height = [cell getCellHeight];
        }

        return height;
    }
    else {
        return 64;
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // See 'How to build an iOS messaging app'
}

#pragma mark - UIImagePickerControllerDelegate
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    // See 'How to build an iOS messaging app'
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [picker dismissViewControllerAnimated:YES completion:^{
        openImagePicker = NO;
    }];
}

#pragma mark - MessagingViewControllerDelegate
- (void) prepareCloseMessagingViewController
{   
    [self startChattingWithPreviousMessage:NO];
}

@end
