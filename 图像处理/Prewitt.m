I = imread("D:\Desktop\各科ppt\计算机图像处理\wire.bmp");
figure(1);
subplot(2,4,1);
imshow(I);
thresh = 0.1;
title("原图像");
direction = "horizontal";
I1 = edge(I,'Prewitt',thresh,direction);
I1 = zhuanhuan(I1);
subplot(2,4,2);
imshow(I1)
title("Prewitt算子水平方向边缘检测");
direction = "vertical";
I2 = edge(I,'Prewitt',thresh,direction);
I2 = zhuanhuan(I2);
subplot(2,4,3);
imshow(I2)
title("Prewitt算子垂直方向边缘检测");
direction = "both";
I3 = edge(I,'Prewitt',thresh,direction);
I3 = zhuanhuan(I3);
subplot(2,4,4);
imshow(I3)
title("Prewitt算子各个方向边缘检测");

I = I*255;
j=imnoise(I,'salt & pepper',0.04)%叠加椒盐噪声
subplot(2,4,5);
imshow(j);
title("椒盐噪声污染后的原图像");
direction = "horizontal";
I1 = edge(j,'Prewitt',thresh,direction);
I1 = zhuanhuan(I1);
subplot(2,4,6);
imshow(I1)
title("Prewitt算子水平方向边缘检测");
direction = "vertical";
I2 = edge(j,'Prewitt',thresh,direction);
I2 = zhuanhuan(I2);
subplot(2,4,7);
imshow(I2)
title("Prewitt算子垂直方向边缘检测");
direction = "both";
I3 = edge(j,'Prewitt',thresh,direction);
I3 = zhuanhuan(I3);
subplot(2,4,8);
imshow(I3)
title("Prewitt算子各个方向边缘检测");