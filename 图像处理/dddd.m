I= imread("D:\Desktop\各科ppt\计算机图像处理\coins.png");
figure
subplot(221),imshow(I)
title('原图像');
Y=fft2(im2double(I));%傅里叶变换
Y=fftshift(Y);%频谱搬移,直流分量搬移到频谱中心
subplot(222);
imshow(log(abs(Y)+1),[])
title('图像傅里叶变换取对数所得频谱');
[a,b]=size(Y);%获得图像的高度和宽度
a0=round(a/2);
b0=round(b/2);
d0=50; % 将理想高通滤波器的截止频率D0设置为50
for i=1:a %双重for循环计算频率点(i,j)与频域中心的距离D(i,j)=sqrt((i-round(a/2)^2+(j-round(b/2)^2))
    for j=1:b 
        distance=sqrt((i-a0)^2+(j-b0)^2);
        if distance<=d0  % 根据理想高通滤波器产生公式,当D(i,j)<=D0,置为1
            h=0;
        else
            h=1;        % 根据理想高通滤波器产生公式,当D(i,j)>D0,置为0
        end
        Y(i,j)=h*Y(i,j);% 频域图像乘以滤波器的系数
    end
end
% real函数取元素的实部
Y=real(ifft2(ifftshift(Y)));% 最后进行二维傅里叶反变换转换为时域图像
subplot(223),imshow(Y,[])
title('理想高通滤波器所得图像'); 

%巴特沃斯低通
Z= imread("D:\Desktop\各科ppt\计算机图像处理\coins.png");
G=fft2(im2double(Z));%傅里叶变换
G=fftshift(G);%频谱搬移,直流分量搬移到频谱中心
[a,b]=size(G);%获得图像的高度和宽度
a0=round(a/2);
b0=round(b/2);
n = 2;
d0=30; % 将理想高通滤波器的截止频率D0设置为50
for i=1:a %双重for循环计算频率点(i,j)与频域中心的距离D(i,j)=sqrt((i-round(a/2)^2+(j-round(b/2)^2))
    for j=1:b 
       distance=sqrt((i-a0)^2+(j-b0)^2);
        if distance==0 
            h=0; 
        else
            h=1/(1+(d0/distance)^(2*n));% 根据巴特沃斯高通滤波器公式为1/(1+[D(i,j)/D0]^2n)
        end
        G(i,j)=h*G(i,j);% 频域图像乘以滤波器的系数
    end
end
G=real(ifft2(ifftshift(G)));% 最后进行二维傅里叶反变换转换为时域图像
subplot(224),imshow(G,[])
title('巴特沃斯高通滤波所得图像'); 