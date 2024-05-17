
f = imread('D:\Desktop\各科ppt\计算机图像处理\pears.png');
[VG,A,PPG] = colorgrad(f);
ppg = im2uint8(PPG);
ppgf = 255 - ppg;
[M,N] = size(ppgf);
T=20;
ppgf1 = zeros(M,N);
for ii = 1:M
    for jj = 1:N
        if ppgf(ii,jj)<T %边缘区域
            ppgf1(ii,jj)=(T-ppgf1(ii,jj))/5;%加深边缘
        else %平滑区域
            ppgf1(ii,jj)=235/(255-T)*(ppgf(ii,jj)-T);%使平滑区域明显
        end
    end
end
ppgf1 = uint8(ppgf1);
figure;imshow(ppgf1);