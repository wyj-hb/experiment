f=imread("D:\Desktop\各科ppt\计算机图像处理\pears.png");
figure
subplot(2,2,1);
imshow(f);
title("原始图像");
f = rgb2gray(f);
f = im2double(f);
BW=edge(f,'canny',[0.2,0.3],1);  %edge:以灰度图像为输入，'canny'为边缘检测算子
                                  %输出BW为二值图像，边缘处为白（255）其余部分为黑（0）
subplot(2,2,2);
BW = zhuanhuan(BW);
imshow(BW)
title('canny算子处理后的图像')
[row,col]=size(BW);
rhomax=round((row*row+col*col)^0.5);
A=zeros(2*rhomax,180);   %这里，实际上rho的取值范围为[-rhomax,rhomax]，
                         %但是为了后面进行数量统计，转变为[1,2rhomax]
for m=1:row
    for n=1:col
        if BW(m,n)>0 %判断为边缘
            for theta=1:180
                r=theta/180*pi; %角度转换
                rho=round(m*cos(r)+n*sin(r));
                %Hough变换
                rho=rho+rhomax+1;   %坐标平移
                                    %这里的理解，首先matlab中数组是从1开始计数，所以+1；
                                    %数组坐标不能<0，所以 +rhomax
                A(rho,theta)=A(rho,theta)+1;   %数量统计
            end
        end
    end
end
[rho,theta]=find(A>130);   %超过130个点视为共线,rho列号，theta行号
nma=length(rho);
subplot(2,2,3);
imshow(BW)
for i=1:nma
    hold on
    m=1:row;
    r=theta(i)/180*pi;
    n=(rho(i)-rhomax-m*cos(r))/(0.0001+sin(r));
    plot(n,m,'w-','LineWidth',6);
end
title('hough线检测');