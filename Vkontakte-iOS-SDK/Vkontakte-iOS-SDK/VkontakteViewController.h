//
//  VkontakteViewController.h
//  VkontakteTest
//
//  Created by Andrey Yastrebov on 01.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBProgressHUD.h"

@protocol VkontakteViewControllerDelegate;
@interface VkontakteViewController : UIViewController <UIWebViewDelegate, MBProgressHUDDelegate>
{
    id <VkontakteViewControllerDelegate> _delegate;
    MBProgressHUD *_hud;
    UIWebView *_webView;
    
    NSURL *_authLink;
}

@property (assign) id <VkontakteViewControllerDelegate> delegate;  
@property (nonatomic, retain) IBOutlet UIWebView *webView;

- (id)initWithAuthLink:(NSURL *)link;

@end

@protocol VkontakteViewControllerDelegate <NSObject>
@optional
- (void)authorizationDidSucceedWithToke:(NSString *)accessToken 
                                 userId:(NSString *)userId 
                                expDate:(NSDate *)expDate;
- (void)authorizationDidFailedWithError:(NSError *)error;
- (void)authorizationDidCanceled;
@end