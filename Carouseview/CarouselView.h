//
//  CarouselView.h
//  轮播视图
//
//  Created by 张飞 on 15/10/4.
//  Copyright © 2015年 zhangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^imageClickBlock)(NSInteger index);

@interface CarouselView : UIView

/**
 *  轮播的ScrollView
 */
@property(strong,nonatomic) UIScrollView *direct;
/**
 *  轮播的页码
 */
@property(strong,nonatomic) UIPageControl *pageVC;
/**
 *  轮播滚动时间间隔
 */
@property(assign,nonatomic) CGFloat time;

/**
 *  初始化图片格式的CarouselView
 *
 *  @param frame          该轮播视图的位置大小
 *  @param imageNameArray 放置图片的数组
 *  @param clickBlock     点击图片的回调
 *
 *  @return 一个轮播视图
 */
+(instancetype)carouseviewWithtFrame:(CGRect)frame ImageArr:(NSArray *)imageNameArray AndImageClickBlock:(imageClickBlock)clickBlock;

/**
 *  初始化自定义样式的CarouselView
 *
 *  @param frame         该轮播视图的位置大小
 *  @param customViewArr 一个view的数组
 *  @param clickBlock   点击view的事件回调
 *
 *  @return 一个轮播视图
 */
+(instancetype)carouseviewWithtFrame:(CGRect)frame ViewArr:(NSArray *)customViewArr AndClickBlock:(imageClickBlock)clickBlock;

/**
 *  开始定时器
 */
-(void)beginTimer;

/**
 *  销毁定时器
 */
-(void)stopTimer;

@end
