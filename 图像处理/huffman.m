function [h,l] =huffman(p)
if (length(find(p<0))~=0)%如果p矩阵的元素都是小于0的话，进入
    error('Not a probability, negative component');%打印错误信息
end
if (abs(sum(p)-1)<10e-10)%sum函数用于对矩阵关于各列求和,形成一个行向量,如果使其减去1后
    error('Not a probability vector, component do not add to 1')
end
n=length(p);%输出矩阵的最大维数
q=p;
m=zeros(n-1,n);
for i=1:n-1
    [q,l]=sort(q);%q是按照升序对列进行排序后的矩阵,l是矩阵之间的对应位置
    m(i,:)=[l(1:n-i+1),zeros(1,i-1)];
    q=[q(1)+q(2),q(3:n),1];
end
for i=1:n-1
    c(i,:)=blanks(n*n);
end
c(n-1,n)='0';
c(n-1,2*n)='1';
for i=2:n-1
    c(n-i,1:n-1)=c(n-i+1,n*(find(m(n-i+1,:)==1))-(n-2):n*(find(m(n-i+1,:)==1)));
    c(n-i,n)='0';
    c(n-i,n+1:2*n-1)=c(n-i,1:n-1);
    c(n-i,2*n)='1';
    for j=1:i-1
        c(n-i,(j+1)*n+1:(j+2)*n)=c(n-i+1,...
            n*(find(m(n-i+1,:)==j+1)-1)+1:n*find(m(n-i+1,:)==j+1));
    end
end
for i=1:n
    h(i,1:n)=c(1,n*(find(m(1,:)==i)-1)+1:find(m(1,:)==i)*n);
    ll(i)=length(find(h(i,:)~=' '));
end
l=sum(p.*ll);
