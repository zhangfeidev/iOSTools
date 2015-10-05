//
//  MacroUtils.h
//  Author:zhangfei
//  Blog:www.zhangfei.tk
//  Created by 张飞 on 15/10/5.
//  Copyright © 2015年 张飞. All rights reserved.
//

#ifndef MacroUtils_h
#define MacroUtils_h

/***************************** System  ***********************************/
#define SYSTEM_VERSION ([[UIDevice currentDevice] systemVersion])
#define IS_IOS7 ([[[UIDevice currentDevice]systemVersion]floatValue]>=7.0)
#define IS_IOS8 ([[[UIDevice currentDevice]systemVersion]floatValue]>=8.0)
#define IS_IPHONE_SIX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE_FIVE ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE_FOUR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

//适配 3.5\4\4.7\5.5寸屏
#define iPhone4 ([UIScreen mainScreen].bounds.size.height < 568)
#define iPhone5 ([UIScreen mainScreen].bounds.size.height == 568)
#define iPhone6 ([UIScreen mainScreen].bounds.size.height == 667)
#define iPhone6p ([UIScreen mainScreen].bounds.size.height > 667)
/***************************** UI_size  ***********************************/
#define UI_SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define UI_SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)

/***************************** Zlog 调试  ***********************************/

//Zlog 调试 -- 输出 对应的 - 文件 - 行数 - 值  // 也挺好用的，我一般是用的这个

#ifdef DEBUG

#   define ZLog(fmt, ...) NSLog((@"函数名：%s [行号：%d] 打印内容：" fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#else

#   define ZLog(...)

#endif

/***************************** 参数非空判断 **************************************/

#define check_parm_is_NSNull(args) [[args class] isSubclassOfClass:[NSNull class]]?Nil:args   //如 参数是<Null> 则 将其 返回 nil
#define check_parm_is_NSNull_NO(args) [[args class] isSubclassOfClass:[NSNull class]]?@"":args   //如 参数是<Null> 则 将其 返回 @""
#define check_string_value_is_NIL(args)  args==nil?@"":args;

#define FILTER_NIL(args) args == nil? @"":args;


/********************************  常用字体大小  *******************************/

#define FONT_BOLD(size)  [UIFont boldSystemFontOfSize:size]
#define FONT_THIN(size)  [UIFont systemFontOfSize:size]

/******************************  常用色值   ************************************/

#define COLOR_COMMON_CLEAR                 [UIColor clearColor]          //透明色
#define COLOR_COMMON_CLEAR_MENGBAN         [UIColor colorWithWhite:0.0 alpha:0.25]   //通用半透明蒙版颜色

/************************  RGB十六进制颜色快速转换方法   **************************/
//RGB转换
#define UIColorFromHEX(rgbValue) [UIColor  colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0  green:((float)((rgbValue & 0xFF00) >> 8))/255.0  blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define COLOR_MAKE_RGB(r,g,b)    [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define COLOR_MAKE_RGBA(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

/******************************  常用比例   ************************************/

#define SCALE_GOLD_PROPORTION     0.618

/******************************  常用函数   ************************************/

#define GET_IMG(imageName)      [UIImage imageNamed:imageName]                         //获取图片
#define GET_WEAKSELF            __weak __typeof(&*self)weakSelf      = self;//获取weekself
#define GET_STRONGSELF          typeof(weakSelf) __strong strongSelf = weakSelf;//获取stronself

//根据屏幕缩放比例，将像素转换成点
#define POINTS_FROM_PIXELS(__PIXELS) (__PIXELS / [[UIScreen mainScreen] scale])
#define ONE_PIXEL POINTS_FROM_PIXELS(1.0)

#endif /* MacroUtils_h */
