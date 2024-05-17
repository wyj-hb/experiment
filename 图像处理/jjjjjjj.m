function jjjjjjj(p);
% 输入符号概率
N = length(p);
% 将概率排序并获得单步码字排序
code = strings(N-1,N);% 初始化单步过程的码字
reflect = zeros(N-1,N);% 初始化位置对应向量
p_SD = p;% p_SD为每次得到的概率排序数组
for i=1:N-1           % i表示排序后第几个符号
    M = length(p_SD);
    [p_SD,reflect(i,1:M)] = sort(p_SD,'descend');% 将概率从大到小进行排序
    code(i,M) = '1';% 概率最小的是1
    code(i,M-1) = '0';% 概率第二小的定义为0
    p_SD(M-1) = p_SD(M-1)+p_SD(M);% 将最后两个概率相加
    p_SD(M)=[];%将本行的最后一个元素设置为空
end
% 根据位置对应向量和单步过程的码字计算对应码字
CODE = strings(1,N); % 初始化对应码字,CODE(i)对应的是输入时第i个元素所对应的编码
for i=1:N
    column = i;
    for m=1:N-1
        [row,column] = find(reflect(m,:)==column);
        CODE(1,i) = strcat(CODE(1,i),code(m,column));
        % 将最小的两个概率映射成一个
        %如果此时的column值等于改行最后的一列的列值，说明该元素为
        %当前最小元素,在下一行将会和前一个元素合并,那么为找其对应字符
        %应该找其前一列在下一行的对应位置,所以让column减1
        if column==N+1-m
            column = column-1;
        end
    end
end
CODE = reverse(CODE);
% 计算平均码长
for i=1:N
    L(i) = size(char(CODE(1,i)),2);
end
L_ave = sum(L.*p);      
H = sum(-p.*log2(p));   % 计算信源信息熵
yita = H/L_ave;         % 计算编码效率
% 展示输出码字、平均码长和编码效率
disp(['信号符号  ',num2str(0:N-1)]);
disp(['对应概率  ',num2str(p)]);
disp(['对应码字  ',CODE]);
disp(['平均码长',num2str(L_ave)]);
disp(['编码效率',num2str(yita)]);
disp(["信源信息熵",num2str(H)]);
