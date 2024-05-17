function y = my_edge(img,method,T);
%参数method可以是梯度算子、Roberts算子、Prewitt和Sobel算子，T是梯度阈值。
[a,b] = size(img);
img = double(img);
new_img = zeros(a,b);
if method == "tidu"
    for i=1:a-1
        for j=1:b-1
            if abs(img(i,j)-img(i+1,j)) + abs(img(i,j)-img(i,j+1))>T
                new_img(i,j) = 50;
            else
                new_img(i,j) = 0;
            end
        end
    end
elseif method == "roberts"
    roberts_x = [1,0;0,-1];
    roberts_y = [0,-1;1,0];
    for i = 1:a - 1
        for j = 1:b-1
            funBox = img(i:i+1,j:j+1);
            G_x = roberts_x .* funBox;
            G_x = abs(sum(G_x(:)));
            G_y = roberts_y .* funBox;
            G_y = abs(sum(G_y(:)));
            roberts_xy  = G_x * 0.5 + G_y * 0.5;
            if roberts_xy>T
                new_img(i,j) = 50;
            else
                new_img(i,j) = 0;
            end
        end
    end
elseif method == "Prewitt"
    sobel_x = [-1,0,1;-1,0,1;-1,0,1];
    sobel_y = [-1,-1,-1;0,0,0;1,1,1];
    for i = 1:a - 2
        for j = 1:b - 2
            funBox = img(i:i+2,j:j+2);
            G_x = sobel_x .* funBox;
            G_x = abs(sum(G_x(:)));
            G_y = sobel_y .* funBox;
            G_y = abs(sum(G_y(:)));
            sobelxy  = G_x * 0.5 + G_y * 0.5;
            if sobelxy >T
                new_img(i+1,j+1) = 50;
            else
                new_img(i+1,j+1) = 0;
            end
        end
    end
else
    sobel_x = [-1,0,1;-2,0,2;-1,0,1];
    sobel_y = [-1,-2,-1;0,0,0;1,2,1];
    for i = 1:a - 2
        for j = 1:b - 2
            funBox = img(i:i+2,j:j+2);
            G_x = sobel_x .* funBox;
            G_x = abs(sum(G_x(:)));
            G_y = sobel_y .* funBox;
            G_y = abs(sum(G_y(:)));
            sobelxy  = G_x * 0.5 + G_y * 0.5;
            if sobelxy >T
                new_img(i+1,j+1) = 0;
            else
                new_img(i+1,j+1) = 50;
            end
        end
    end
end
y = new_img;

