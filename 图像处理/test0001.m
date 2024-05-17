img = imread("D:\Desktop\各科ppt\计算机图像处理\lena512.jpg");
figure;
subplot(3,2,1)
imshow(img),title("原图像");
[ROW,COL] = size(img);
img = double(img);
new_img = zeros(ROW,COL); %新建画布
%定义robert算子
roberts_x = [1,0;0,-1];
roberts_y = [0,-1;1,0];
for i = 1:ROW - 1
    for j = 1:COL - 1
        funBox = img(i:i+1,j:j+1);
        G_x = roberts_x .* funBox;%矩阵对应位置元素相乘
        G_x = abs(sum(G_x(:)));%求和
        G_y = roberts_y .* funBox;
        G_y = abs(sum(G_y(:)));
        roberts_xy  = G_x * 0.5 + G_y * 0.5;
        new_img(i,j) = roberts_xy;
    end
end
subplot(3,2,2);
imshow(new_img/255),title("robert算子的图像");
%定义sobel算子
sobel_x = [-1,0,1;-2,0,2;-1,0,1];
sobel_y = [-1,-2,-1;0,0,0;1,2,1];
for i = 1:ROW - 2
    for j = 1:COL - 2
        funBox = img(i:i+2,j:j+2);
        G_x = sobel_x .* funBox;
        G_x = abs(sum(G_x(:)));
        G_y = sobel_y .* funBox;
        G_y = abs(sum(G_y(:)));
        sobelxy  = G_x * 0.5 + G_y * 0.5;
        new_img(i+1,j+1) = sobelxy;
    end
end
subplot(3,2,4);
imshow(new_img/255);title("sobel的图像");
%定义Prewitt算子
sobel_x = [-1,0,1;-1,0,1;-1,0,1];
sobel_y = [-1,-1,-1;0,0,0;1,1,1];
for i = 1:ROW - 2
    for j = 1:COL - 2
        funBox = img(i:i+2,j:j+2);
        G_x = sobel_x .* funBox;
        G_x = abs(sum(G_x(:)));
        G_y = sobel_y .* funBox;
        G_y = abs(sum(G_y(:)));
        sobelxy  = G_x * 0.5 + G_y * 0.5;
        new_img(i+1,j+1) = sobelxy;
    end
end
subplot(3,2,5);
imshow(new_img/255);title("Prewitt的图像");