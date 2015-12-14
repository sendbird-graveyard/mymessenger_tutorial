//
//  SettingsViewController.m
//  MyMessenger
//
//  Created by Jed Kyung on 12/7/15.
//  Copyright © 2015 JIVER.CO. All rights reserved.
//

#import "SettingsViewController.h"

@interface SettingsViewController ()<UIImagePickerControllerDelegate, UINavigationControllerDelegate> {
    NSString *profileImageUrl;
    NSString *profileNickname;
}

@end

@implementation SettingsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.profileImageView.layer.cornerRadius = self.profileImageViewHeight.constant / 2;
    [self.profileImageView.layer setBorderColor:[[UIColor purpleColor] CGColor]];
    [self.nicknameTextField.layer setBorderColor:[[UIColor blueColor] CGColor]];
    [self.imageLoadingIndicator setHidden:YES];
    [self loadProfileImage:[MyUtils getUserProfileImage]];
    [self.nicknameTextField setText:[MyUtils getUserName]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)closeViewController:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)loadProfileImage:(NSString *)imageUrl
{
    [self.imageLoadingIndicator setHidden:NO];
    [self.imageLoadingIndicator startAnimating];
    profileImageUrl = imageUrl;
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    [request setHTTPMethod:@"GET"];
    [request setValue:[NSString stringWithFormat:@"Jios/%@", [Jiver VERSION]] forHTTPHeaderField:@"User-Agent"];
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
        [self.imageLoadingIndicator setHidden:YES];
        [self.imageLoadingIndicator stopAnimating];
    } failure:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, NSError * _Nonnull error) {
        [self.imageLoadingIndicator setHidden:YES];
        [self.imageLoadingIndicator stopAnimating];
    }];
}

- (IBAction)saveProfile:(id)sender {
    profileNickname = [self.nicknameTextField text];
    [MyUtils setUserName:profileNickname];
    [MyUtils setUserProfileImage:profileImageUrl];
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)openImagePicker:(id)sender {
    UIImagePickerController *mediaUI = [[UIImagePickerController alloc] init];
    mediaUI.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    NSMutableArray *mediaTypes = [[NSMutableArray alloc] initWithObjects:(NSString *)kUTTypeImage, nil];
    mediaUI.mediaTypes = mediaTypes;
    [mediaUI setDelegate:self];
    [self presentViewController:mediaUI animated:YES completion:nil];
}

#pragma mark - UIImagePickerControllerDelegate
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    __block NSString *mediaType = [info objectForKey: UIImagePickerControllerMediaType];
    __block UIImage *originalImage, *editedImage, *imageToUse;
    __block NSURL *imagePath;
    __block NSString *imageName;
    
    [picker dismissViewControllerAnimated:YES completion:^{
        if (CFStringCompare ((CFStringRef) mediaType, kUTTypeImage, 0) == kCFCompareEqualTo) {
            editedImage = (UIImage *) [info objectForKey:
                                       UIImagePickerControllerEditedImage];
            originalImage = (UIImage *) [info objectForKey:
                                         UIImagePickerControllerOriginalImage];
            
            if (originalImage) {
                imageToUse = originalImage;
            } else {
                imageToUse = editedImage;
            }
            
            CGFloat width = 500;
            CGFloat height = originalImage.size.height * (500 / originalImage.size.width);
            
            UIGraphicsBeginImageContext(CGSizeMake(width, height));
            [imageToUse drawInRect:CGRectMake(0, 0, width, height)];
            UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
            UIGraphicsEndImageContext();
            
            NSData *imageFileData = UIImagePNGRepresentation(newImage);
            imagePath = [info objectForKey:@"UIImagePickerControllerReferenceURL"];
            imageName = [imagePath lastPathComponent];
            [self.imageLoadingIndicator setHidden:NO];
            [self.imageLoadingIndicator startAnimating];
            [Jiver uploadFile:imageFileData type:@"image/jpg" hasSizeOfFile:[imageFileData length] withCustomField:@"" uploadBlock:^(JiverFileInfo *fileInfo, NSError *error) {
                profileImageUrl = [fileInfo url];
                [self loadProfileImage:profileImageUrl];
            }];
        }
    }];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [picker dismissViewControllerAnimated:YES completion:^{

    }];
}


@end
