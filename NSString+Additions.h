//
//  NSString+Additions.h
//  VVeboTableViewDemo
//
//  Created by 尚勇杰 on 2017/12/5.
//  Copyright © 2017年 Johnil. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>
@interface NSString (Additions)

#pragma mark - java api


/**
 比较大小

 @param comp 比较的字符串
 @return 结果  相同 0 小于 -1 大于 1
 */
- (NSUInteger) compareTo: (NSString*) comp;

/**
 比较大小 （忽略大小写）
 
 @param comp 比较的字符串
 @return 结果  相同 0 小于 -1 大于 1
 */
- (NSUInteger) compareToIgnoreCase: (NSString*) comp;

/**
 是否包含substring

 @param substring <#substring description#>
 @return <#return value description#>
 */
- (bool) contains: (NSString*) substring;

/**
 是否以substring结尾

 @param substring <#substring description#>
 @return <#return value description#>
 */
- (bool) endsWith: (NSString*) substring;

/**
 是否从substring开始

 @param substring <#substring description#>
 @return <#return value description#>
 */
- (bool) startsWith: (NSString*) substring;

/**
 substring的开始位置

 @param substring <#substring description#>
 @return 有返回location 没有则返回-1
 */
- (NSUInteger) indexOf: (NSString*) substring;

/**
 返回substring的开始位置 以给定的位置开始算起

 @param substring <#substring description#>
 @param index <#index description#>
 @return <#return value description#>
 */
- (NSUInteger) indexOf:(NSString *)substring startingFrom: (NSUInteger) index;

/**
 substring结束的位置

 @param substring <#substring description#>
 @return <#return value description#>
 */
- (NSUInteger) lastIndexOf: (NSString*) substring;

/**
 substring结束的位置,以给定的位置开始算

 @param substring <#substring description#>
 @param index <#index description#>
 @return <#return value description#>
 */
- (NSUInteger) lastIndexOf:(NSString *)substring startingFrom: (NSUInteger) index;

/**
 从一个位置到另一个位置的字符串

 @param from <#from description#>
 @param to <#to description#>
 @return <#return value description#>
 */
- (NSString*) substringFromIndex:(NSUInteger)from toIndex: (NSUInteger) to;

/**
 去除字符串两端的空格与回车

 @return <#return value description#>
 */
- (NSString*) trim;

/**
 字符串分割

 @param token <#token description#>
 @return <#return value description#>
 */
- (NSArray*) split: (NSString*) token;

/**
 字符串分割，

 @param token 字符串
 @param maxResults 最多返回几个结果
 @return <#return value description#>
 */
- (NSArray*) split: (NSString*) token limit: (NSUInteger) maxResults;

/**
 以replacement替换target

 @param target <#target description#>
 @param replacement <#replacement description#>
 @return <#return value description#>
 */
- (NSString*) replace: (NSString*) target withString: (NSString*) replacement;

/**
 自定义计算字符串的大小

 @param width 宽度
 @param font1 字体
 @param lineSpace 字体间隔
 @return <#return value description#>
 */
- (CGSize)sizeWithConstrainedToWidth:(float)width fromFont:(UIFont *)font1 lineSpace:(float)lineSpace;

/**
 自定义计算字符串的大小 传进一个size

 @param size 大小
 @param font1 字体
 @param lineSpace 字体间隔
 @return <#return value description#>
 */
- (CGSize)sizeWithConstrainedToSize:(CGSize)size fromFont:(UIFont *)font1 lineSpace:(float)lineSpace;

/**
 描点

 @param context <#context description#>
 @param p <#p description#>
 @param font <#font description#>
 @param color <#color description#>
 @param height <#height description#>
 @param width <#width description#>
 */
- (void)drawInContext:(CGContextRef)context withPosition:(CGPoint)p andFont:(UIFont *)font andTextColor:(UIColor *)color andHeight:(float)height andWidth:(float)width;

/**
 不指定宽度描点

 @param context <#context description#>
 @param p <#p description#>
 @param font <#font description#>
 @param color <#color description#>
 @param height <#height description#>
 */
- (void)drawInContext:(CGContextRef)context withPosition:(CGPoint)p andFont:(UIFont *)font andTextColor:(UIColor *)color andHeight:(float)height;

@end

