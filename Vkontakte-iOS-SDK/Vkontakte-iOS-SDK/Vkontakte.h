//
//  Vkontakte.h
//  VkontakteTest
//
//  Created by Andrey Yastrebov on 01.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VkontakteViewController.h"

extern NSString * const vkAppId;

@protocol VkontakteDelegate;

@interface Vkontakte : NSObject <VkontakteViewControllerDelegate>
{
    id <VkontakteDelegate> _delegate;
    
    NSString *_accessToken;
    NSDate *_expirationDate;
    NSString *_userId;
    
    BOOL _isCaptcha;
}

@property (assign) id <VkontakteDelegate> delegate;
@property (nonatomic, retain) NSString *userId;
@property (nonatomic, retain) NSDate *expirationDate;
@property (nonatomic, retain) NSString *accessToken;

+ (id)sharedInstance;
- (BOOL)isAuthorized;
- (void)authenticate;
- (void)logout;
- (void)getUserInfo;
- (void)postMessageToWall:(NSString *)message;
- (void)postMessageToWall:(NSString *)message link:(NSURL *)url;
- (void)postImageToWall:(UIImage *)image;
- (void)postImageToWall:(UIImage *)image text:(NSString *)message;

@end

@protocol VkontakteDelegate <NSObject>
@required
- (void)vkontakteDidFailedWithError:(NSError *)error;
- (void)showVkontakteAuthController:(UIViewController *)controller;
- (void)vkontakteAuthControllerDidCancelled;
@optional
- (void)vkontakteDidFinishLogin:(Vkontakte *)vkontakte;
- (void)vkontakteDidFinishLogOut:(Vkontakte *)vkontakte;

- (void)vkontakteDidFinishGettinUserInfo:(NSDictionary *)info;
- (void)vkontakteDidFinishPostingToWall:(NSDictionary *)responce;

@end
