//
//  ViewController.h
//  Vkontakte-iOS-SDK
//
//  Created by Andrey Yastrebov on 02.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Vkontakte.h"

@interface ViewController : UIViewController <VkontakteDelegate>
{
    IBOutlet UIButton *_loginB;
    
    IBOutlet UIImageView *_userImage;
    IBOutlet UILabel *_userName;
    IBOutlet UILabel *_userSurName;
    IBOutlet UILabel *_userBDate;
    IBOutlet UILabel *_userGender;
    
    IBOutlet UIButton *_postMessage;
    IBOutlet UIButton *_postImage;
    IBOutlet UIButton *_postMessageWithLink;
    IBOutlet UIButton *_postImageWithLink;
    
    Vkontakte *_vkontakte;    
}

- (IBAction)loginPressed:(id)sender;

- (IBAction)postMessagePressed:(id)sender;
- (IBAction)postImagePressed:(id)sender;
- (IBAction)postMessageWithLinkPressed:(id)sender;
- (IBAction)postImageWithLinkPressed:(id)sender;

- (void)refreshButtonState;
- (void)hideControls:(BOOL)hide;

@end
