
I = imread("D:\Desktop\各科ppt\计算机图像处理\rice.png");
figure;
subplot(3,1,1);
imshow(I);
title("原始图像");
subplot(3,1,2);
I1 = rgb2gray(I);
imshow(I1);
title("灰度图像");
subplot(3,1,3);
I2 = im2bw(I)
imshow(I2);
title("二值图像");