//
//  HaiLabel.h
//  label
//
//  Created by imac on 16/6/18.
//  Copyright © 2016年 imac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

@class HaiLabel;
@protocol HaiLabelDelegate <NSObject>

@optional

//手指离开当前超链接文本响应的协议方法
- (void)toucheEndHaiLabel:(HaiLabel *)haiLabel withContext:(NSString *)context;
//手指接触当前超链接文本响应的协议方法
- (void)toucheBenginHaiLabel:(HaiLabel *)haiLabel withContext:(NSString *)context;

/*
 - (NSString *)contentsOfRegexStringWithWHaiabel:(HaiLabel *)haiLabel
 {
 //需要添加链接字符串的正则表达式：@用户、http://、#话题#
 NSString *regex1 = @"@\\w+";
 NSString *regex2 = @"http(s)?://([A-Za-z0-9._-]+(/)?)*";
 NSString *regex3 = @"#\\w+#";
 NSString *regex = [NSString stringWithFormat:@"(%@)|(%@)|(%@)",regex1,regex2,regex3];
 return regex;
 }
 */
//检索文本的正则表达式的字符串
- (NSString *)contentsOfRegexStringWithHaiLabel:(HaiLabel *)haiLabel; 
//设置当前链接文本的颜色
- (UIColor *)linkColorWithHaiLabel:(HaiLabel *)haiLabel;
//设置当前文本手指经过的颜色
- (UIColor *)passColorWithHaiLabel:(HaiLabel *)haiLabel;

/*
 注意：
 默认表达式@"<image url = '[a-zA-Z0-9_\\.@%&\\S]*'>"
 可以通过代理方法修改正则表达式，不过本地图片地址的左右（＊＊＊一定要用单引号引起来）
 */
//检索文本中图片的正则表达式的字符串
- (NSString *)imagesOfRegexStringWithHaiLabel:(HaiLabel *)haiLabel;
@end



@interface HaiLabel : UILabel

@property(nonatomic,assign)id<HaiLabelDelegate> haiLabelDelegate;//代理对象
@property(nonatomic,assign)CGFloat linespace;//行间距   default = 10.0f
@property(nonatomic,assign)CGFloat mutiHeight;//行高(倍数) default = 1.0f
@property(nonatomic,assign)float textHeight;//计算文本内容的高度
+ (float)getTextHeight:(float)fontSize
                 width:(float)width
                  text:(NSString *)text;
@end
