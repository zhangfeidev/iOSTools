//
//  QRCScanner.h
//  QRScannerDemo
//
//  Created by zhangfei on 15/10/15.
//  Copyright © 2015年 zhangfei. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol QRCodeScanneDelegate <NSObject>
/**
 *  扫描成功后返回扫描结果
 *
 *  @param result 扫描结果
 */
- (void)didFinshedScanningQRCode:(NSString *)result;

@end

@interface QRCScanner : UIView
/**
 *  扫描线的颜色,默认红色
 */
@property (nonatomic,strong)UIColor *scanningLieColor;
/**
 *  扫描框边角的颜色，默认红色
 */
@property (nonatomic,strong)UIColor *cornerLineColor;
/**
 *  扫描框的宽高区域，默认(200，200)
 */
@property (nonatomic,assign)CGSize transparentAreaSize;
/**
 *  代理
 */
@property (nonatomic,assign) id<QRCodeScanneDelegate>delegate;
/**
 *  初始化方法
 *
 *  @param QRCScannerView的父view
 *
 *  @return QRCScanner实例
 */
- (instancetype)initQRCScannerWithView:(UIView *)view;
@end
