
in='badbdbc';          
pr=[0.1,0.4,0.2,0.3];        %各字符出现的概率  
temp=[0.0 0.1 0.5 0.7 1.0];  %区间
orignal=temp;  
n=length(in);
a = length(orignal)
%编码  
for i=1:n  
    width=temp(a)-temp(1);  
    w=temp(1);  
    switch in(i)  
        case 'a'  
            m=1;%第一个区间
        case 'b'  
            m=2;%第二个区间
        case 'c'  
            m=3;%第三个区间
        case 'd'  
            m=4;%第四个区间
    end
    temp(1)=w+orignal(m)*width;%定义新的空间范围
    temp(a)=w+orignal(m+1)*width;
    left=temp(1);
    right=temp(a);  
    fprintf('left=%.6f',left);%打印输出范围值
    fprintf('    ');  
    fprintf('right=%.6f\n',right);
end  
encode=(temp(1)+temp(a))/2%取最终范围的中间值为作为输出
%解码
decode=['a'];
for i=1:n  
    fprintf('tmp=%.6f\n',encode);  
    if(encode>=orignal(1) & encode<orignal(2))%根据当前空间范围值选出字符
        decode(i)='a';  
        t=1;  
    elseif(encode>=orignal(2) & encode<orignal(3))  
        decode(i)='b';  
        t=2;
     elseif(encode>=orignal(3) & encode<orignal(4))  
        decode(i)='c';  
        t=3;  
     elseif(encode>=orignal(4) & encode<orignal(5))  
        decode(i)='d';  
        t=4;  
    end
    encode=(encode-orignal(t));%将字符恢复为原来对应的空间进行判断  
    encode=encode/pr(t);
end  
decode
%算术编码子程序：输入字符行向量symbol、字符出现的概率pr、待编码字符串seqin
%设信源符号为X={a,b,c,d}，各符号出现的概率为P(X)={0.1,0.4,0.2,0.3}；输入的消息序列为badbdbc。
