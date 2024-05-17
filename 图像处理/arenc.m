function arcode=arenc(symbol,pr,seqin)
%算术编码子程序：输入字符行向量symbol、字符出现的概率pr、待编码字符串seqin
high_range=[];
for k=1:length(pr)
    high_range=[high_range sum(pr(1:k))];
end
low_range=[0 high_range(1:length(pr)-1)];
sbidx=zeros(size(seqin));
for i=1:length(seqin)
    sbidx(i)=find(symbol==seqin(i));
end
low=0; high=1;
for i=1:length(seqin)
    range=high-low;
    high=low+range*high_range(sbidx(i));
    low=low+range*low_range(sbidx(i));
end
M=20; lable=zeros(1,M); number=0;
for i=1:M
    if number>=low & number<high
        break;
    else
        number1=number+(0.5)^i;
        number2=number+0;
    end
    if number1<=high
        number=number1; lable(i)=1;
    else
        number=number2; lable(i)=0;
    end
end
arcode=lable(1:i-1); %或取区间下限作为对源数据流进行压缩后的编码arcode=low;

function symseq=ardec(symbol,pr,codestring,symlen)
%算术解码子程序：输入给定字符概率的待解码数值码串codestring及码串长度symlen
codeword=0;
for i=1:length(codestring)
    codeword=codeword+codestring(i)*(2^(-i));
end
high_range=[];
for k=1:length(pr)
    high_range=[high_range sum(pr(1:k))];
end
low_range=[0 high_range(1:length(pr)-1)];
prmin=min(pr);
symseq=[];
for i=1:symlen
    idx=max(find(low_range<=codeword));
    codeword=codeword-low_range(idx);
    if abs(codeword-pr(idx))<0.01*prmin
        idx=idx+1;
        codeword=0;
    end
    symseq=[symseq symbol(idx)];
    codeword=codeword/pr(idx);
    if abs(codeword)<0.01*prmin
        i=symlen+1;
    end
end
