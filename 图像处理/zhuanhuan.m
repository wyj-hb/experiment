function g = zhuanhuan(y);
[M N] = size(y);
for i=1:M
    for j=1:N
        if y(i,j) == 0
            y(i,j) = 50;
        else
            y(i,j) = 0;
        end
    end
end
g = y;