//
//  UIScreen+Additions.m
//  VVeboTableViewDemo
//
//  Created by 尚勇杰 on 2017/12/5.
//  Copyright © 2017年 Johnil. All rights reserved.
//

#import "UIScreen+Additions.h"

@implementation UIScreen (Additions)

+ (float)screenWidth{
    
    //    dispatch_async(dispatch_get_main_queue(), ^{
    
    if (UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)) {
        
        
        if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
            return [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale;
        } else {
            return [UIScreen mainScreen].bounds.size.height;
        }
    } else {
        if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
            return [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale;
        } else {
            return [UIScreen mainScreen].bounds.size.width;
        }
    }
    //    });
    
}

+ (float)screenHeight{
    if (UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)) {
        if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
            if ([UIApplication sharedApplication].statusBarFrame.size.width>20) {
                return [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale-20;
            }
            return [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale;
            
            
        } else {
            if ([UIApplication sharedApplication].statusBarFrame.size.width>20) {
                return [UIScreen mainScreen].bounds.size.width-20;
            }
            return [UIScreen mainScreen].bounds.size.width;
        }
    } else {
        if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
            if ([UIApplication sharedApplication].statusBarFrame.size.height>20) {
                return [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale-20;
            }
            return [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale;
        } else {
            if ([UIApplication sharedApplication].statusBarFrame.size.height>20) {
                return [UIScreen mainScreen].bounds.size.height-20;
            }
            return [UIScreen mainScreen].bounds.size.height;
        }
    }
}

+ (BOOL)isRetina{
    if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
        return [UIScreen mainScreen].nativeScale >= 2;
    } else {
        return [UIScreen mainScreen].scale >= 2;
    }
}

+ (float)scale{
    if ([[UIDevice currentDevice].systemVersion floatValue]>=8.0) {
        return [UIScreen mainScreen].nativeScale;
    } else {
        return [UIScreen mainScreen].scale;
    }
}

@end
