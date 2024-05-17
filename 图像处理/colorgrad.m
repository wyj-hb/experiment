function [VG, A, PPG] = colorgrad(f, T)%传入图像f和阈值T
if (ndims(f)~=3) || (size(f,3)~=3)%传入的图像需要是rgb图像，dim等于3
    error('Input image must be RGB');
end
sh = fspecial('sobel');%生成sobel滤波器，用于边缘提取
sv = sh';
Rx = imfilter(double(f(:,:,1)), sh, 'replicate');%对第一幅图像进行sobel算子处理
Ry = imfilter(double(f(:,:,1)), sv, 'replicate');
Gx = imfilter(double(f(:,:,2)), sh, 'replicate');
Gy = imfilter(double(f(:,:,2)), sv, 'replicate');
Bx = imfilter(double(f(:,:,3)), sh, 'replicate');
By = imfilter(double(f(:,:,3)), sv, 'replicate');
gxx = Rx.^2 + Gx.^2 + Bx.^2;%获的新rgb图像的像素值
gyy = Ry.^2 + Gy.^2 + By.^2;
gxy = Rx.*Ry + Gx.*Gy + Bx.*By;
A = 0.5*(atan(2*gxy./(gxx-gyy+eps)));
G1 = 0.5*((gxx+gyy) + (gxx-gyy).*cos(2*A) + 2*gxy.*sin(2*A));
A = A + pi/2;
G2 = 0.5*((gxx+gyy) + (gxx-gyy).*cos(2*A) + 2*gxy.*sin(2*A));
G1 = G1.^0.5;
G2 = G2.^0.5;
VG = mat2gray(max(G1, G2));
RG = sqrt(Rx.^2 + Ry.^2);
GG = sqrt(Gx.^2 + Gy.^2);
BG = sqrt(Bx.^2 + By.^2);
PPG = mat2gray(RG + GG + BG);
if nargin ==2
    VG = (VG>T).*VG;
    PPG = (PPG>T).*PPG;
end