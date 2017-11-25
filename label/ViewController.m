//
//  ViewController.m
//  label
//
//  Created by imac on 16/6/18.
//  Copyright © 2016年 imac. All rights reserved.
//

#import "ViewController.h"
#import "HaiLabel.h"

@interface ViewController ()<HaiLabelDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    HaiLabel *haiLabel = [[HaiLabel alloc] initWithFrame:CGRectMake(90, 90, 190, 190)];
    
    haiLabel.text = @"@fasfm";
//    haiLabel.textColor = [UIColor blackColor];
    //设置代理
    haiLabel.haiLabelDelegate = self;
    
    [self.view addSubview:haiLabel];
    
}

#pragma mark - HaiLabelDelegate
//检索文本的正则表达式的字符串
- (NSString *)contentsOfRegexStringWithHaiLabel:(HaiLabel *)haiLabel{
    /*
     @某人
     #话题#
     http     \\bhttp(s)?://([0-9a-zA-Z.-_&]+(/)?)+
     \\bhttp(s)?://([0-9a-zA-Z._-&]+(/)?)+  有问题, -&
     */
    NSString *regexStr1 = @"@\\w+";
    NSString *regexStr2 = @"#[^#]+#";
    NSString *regexStr3 = @"\\bhttp(s)?://([0-9a-zA-Z.-_&]+(/)?)+";
    
    NSString *regexStr = [NSString stringWithFormat:@"%@|%@|%@",regexStr1,regexStr2,regexStr3];
    return regexStr;
}

//设置当前链接文本的颜色
- (UIColor *)linkColorWithHaiLabel:(HaiLabel *)haiLabel{
    
    return [UIColor blueColor];;
    
}

//设置当前文本手指经过的颜色
- (UIColor *)passColorWithHaiLabel:(HaiLabel *)haiLabel{
    
    return [UIColor greenColor];
    
}

//手指离开当前超链接文本响应的协议方法
- (void)toucheEndHaiLabel:(HaiLabel *)haiLabel withContext:(NSString *)context{
    
    NSLog(@"context:%@",context);
}



@end
