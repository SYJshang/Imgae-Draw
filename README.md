# imageDraw 图片裁剪
## 利用图像绘制对图片进行各种处理
* **圆形图片**


```
+(UIImage *)getCircleImageWithImageName:(NSString *)imageName size:(CGSize)size {
    
    UIImage *oldImage = [UIImage imageNamed:imageName];
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0);// 开启图形上下文
    CGContextRef ctr = UIGraphicsGetCurrentContext();// 获取上下文
    
    CGRect rect = CGRectMake(0, 0, size.width, size.height);// 设置圆形
    CGContextAddEllipseInRect(ctr, rect);
    
    CGContextClip(ctr);// 裁剪
    [oldImage drawInRect:rect];// 将图片画上去
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();// 获取新的图片
    UIGraphicsEndImageContext();// 关闭图形上下文
    return newImage;
}
```

* **圆角处理**
	
	```
	+(UIImage *)imageWithImageName:(NSString *)imageName size:(CGSize)size radius:(CGFloat)radius {
    
    CGRect rect = CGRectMake(0, 0, size.width, size.height);
    UIImage *oldImage = [UIImage imageNamed:imageName];
    UIGraphicsBeginImageContextWithOptions(size, NO, 1.0);
    
    [[UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:radius] addClip];
    [oldImage drawInRect:rect];
    
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}
	```
* **修改图片大小**

```
- (UIImage *)turnImageWithSize:(CGSize)size {
    
    float scale = self.size.width/self.size.height;
    CGRect rect = CGRectMake(0, 0, 0, 0);
    
    if (scale > size.width/size.height) {
        
        rect.origin.x = (self.size.width - self.size.height * size.width/size.height)/2;
        rect.size.width  = self.size.height * size.width/size.height;
        rect.size.height = self.size.height;
        
    }else {
        
        rect.origin.y = (self.size.height - self.size.width/size.width * size.height)/2;
        rect.size.width  = self.size.width;
        rect.size.height = self.size.width/size.width * size.height;
        
    }
    
    CGImageRef imageRef   = CGImageCreateWithImageInRect(self.CGImage, rect);
    UIImage *croppedImage = [UIImage imageWithCGImage:imageRef];
    CGImageRelease(imageRef);
    
    return croppedImage;
}

```