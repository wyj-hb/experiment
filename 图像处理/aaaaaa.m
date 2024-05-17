clear all;
clc;
in='00000011111010101';          
pr=[0.5 0.5];        %各字符出现的概率  
temp=[0.0 0.5 1.0];  %区间
orignal=temp;  
 
n=length(in);  
%编码  
for i=1:n  
    width=temp(3)-temp(1);  
    w=temp(1);  
    switch in(i)  
        case '0'  
            m=1;%第一个区间
        case '1'  
            m=2;%第二个区间
    end
    temp(1)=w+orignal(m)*width;%定义新的空间范围
    temp(3)=w+orignal(m+1)*width;  
    left=temp(1);  
    right=temp(3);  
    fprintf('left=%.6f',left);  
    fprintf('    ');  
    fprintf('right=%.6f\n',right);  
end  
encode=(temp(1)+temp(3))/2 
 
%解码  
decode=['0'];  
for i=1:n  
    fprintf('tmp=%.6f\n',encode);  
    if(encode>=orignal(1)& encode<orignal(2))  
        decode(i)='0';  
        t=1;  
    elseif(encode>=orignal(2)& encode<orignal(3))  
        decode(i)='1';  
        t=2;  
    end  
    encode=(encode-orignal(t));  
    encode=encode/pr(t);  
end  
decode 