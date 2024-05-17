function f = pinlv(b);
[M N] = size(b);
size1 = M*N;
A = zeros(1,10);%数字范围是0-9
for i=1:M
    for j=1:N
        A(b(i,j)+1)=A(b(i,j)+1)+1;
    end
end
a = im2double(A)
a = a/size1
f = a;
        