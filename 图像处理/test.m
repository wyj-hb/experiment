p = [5 5 4 4 2 0 7;5 5 4 2 0 0 7;4 4 4 2 0 7 7;1 3 3 0 7 7 6;1 0 0 0 7 7 6;
    7 7 7 7 7 7 6;7	7 7 7 7	7 6];
if (length(find(p<0))~=0)%如果p矩阵的元素都是小于0的话，进入
    error('Not a probability, negative component');%打印错误信息
end
if (abs(sum(p)-1)<10e-10)%sum函数用于对矩阵关于各列求和,形成一个行向量,如果使其减去1后
    error('Not a probability vector, component do not add to 1')
end
n=length(p);%输出矩阵的最大维数
q=p;%复制一个新的矩阵
m=zeros(n-1,n);%生成一个6行7列的矩阵
for i=1:n-1
    [q,l]=sort(q);%q是按照升序对列进行排序后的矩阵,l是原矩阵与排序矩阵之间的对应位置
    m(i,:)=[l(1:n-i+1),zeros(1,i-1)];%m中记录的是第i行元素从位置1到位置n-i+1的
    %排序转换前后的下标
    q=[q(1)+q(2),q(3:n),1];
end
for i=1:n-1
    c(i,:)=blanks(n*n);
end