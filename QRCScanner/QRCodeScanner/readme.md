#QRSCanner
##简介
对iOS自带的的二维码/条形码扫描进行了封装；也封装了一个简单的UI，并且实现了照明灯。并且将一个小巧的二维码生成库放到了QRSCanner里面，方便做二维码的生成。
##使用方法
>首先将QRCScanner文件夹拖入工程中，导入QRCScanner.h，接下来在需要的地方实现下面的代码即可。

- 扫描二维码

``` Objective-C
QRCScanner *scanner = [[QRCScanner alloc]initQRCScannerWithView:self.view];
scanner.delegate = self;
[self.view addSubview:scanner];
//然后实现其代理方法- (void)didFinshedScanningQRCode:(NSString *)result即可
```

- 生成二维码

``` Objective-C
self.qrImageView.image = [UIImage mdQRCodeForString:@"你好，这是二维码的内容！" size:self.qrImageView.bounds.size.width fillColor:[UIColor blackColor]];
```