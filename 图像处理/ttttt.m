I = imread("D:\Desktop\各科ppt\计算机图像处理\lena512.jpg");
T = 20;
figure
subplot(2,3,1);
imshow(I)
title("原图像");
subplot(2,3,2);
I1 = my_edge(I,'tidu',T);
imshow(I1)
title("梯度算子处理");
subplot(2,3,3);
I2 = my_edge(I,'sobel',T);
imshow(I2)
title("sobel算子处理");
subplot(2,3,4);
I3 = my_edge(I,'Prewitt',T);
imshow(I3)
title("Prewitt算子处理");
subplot(2,3,5);
I4 = my_edge(I,'roberts',T);
imshow(I4)
title("roberts算子处理");