//
//  NSString+Gender.m
//  VkontakteTest
//
//  Created by Andrey Yastrebov on 02.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "NSString+Gender.h"

@implementation NSString (Gender)
+ (NSString *)stringWithGenderId:(NSUInteger)gId
{
    switch (gId) 
    {
        case 1:
            return @"Женский";
            break;
            
        case 2:
            return @"Мужской";
            break;
            
        default:
            return @"";
            break;
    }
}
@end
