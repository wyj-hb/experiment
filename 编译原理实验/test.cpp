//# include <stdio.h>
//# include <ctype.h>
//#include <string>
//# define ID 6
//# define INT 7
//# define LT 8
//# define LE 9
//# define EQ 10
//# define NE 11
//# define GT 12
//# define GE 13
//char TOKEN[20];
//extern int lookup(string s);
//extern void out(int, char*);
//extern int report_error(void);
////扫描文本
//void scanner_example(FILE* fp)
//{
//	char ch; 
//	int i, c;
//	//从文件中读取一个字符,每次调用更新指针的位置
//	ch = fgetc(fp);
//	//判断字符是否为字母字符
//	if (isalpha(ch))
//	{
//		//将第一个字母记录到TOKEN数组中
//		TOKEN[0] = ch;
//		ch = fgetc(fp); 
//		i = 1;
//		//判断是否是字母
//		while (isalnum(ch))
//		{
//			//循环直到找到第一个不是字母的
//			TOKEN[i] = ch; 
//			i++;
//			ch = fgetc(fp);
//		}
//		//标识字符串的结尾
//		TOKEN[i] = '＼0';
//		//将指针返回上一个位置
//		fseek(fp, -1, 1); 
//		//判断TOKEN是关键字/标识符
//		c = lookup(TOKEN);
//		if (c == 0)
//		{
//			//是标识符
//			out(ID, TOKEN);
//		}
//		else
//		{
//			//是关键字
//			out(c," ");
//		}
//			
//	}
//	else
//		if (isdigit(ch))
//		{
//			TOKEN[0] = ch; ch = fgetc(fp); i = 1;
//			while (isdigit(ch))
//			{
//				TOKEN[i] = ch; i++;
//				ch = fgetc(fp);
//			}
//			TOKEN[i] = '＼0'；
//				fseek(fp, -1, 1);
//			out(INT, TOKEN);
//		}
//		else
//			switch (ch)
//			{
//			case ′＜′: ch = fgetc(fp);
//				if (ch == ′ = ′)out(LE, " ");
//				else if (ch == ′＞′) out(NE, " ");
//				else
//				{
//					fseek(fp, -1, 1);
//					out(LT, " ");
//				}
//				break;
//			case ′ = ′: out(EQ, " "); break;
//			case ′＞′: ch = fgetc(fp);
//				if (ch == ′ = ′)out(GE, " ");
//				else
//				{
//					fseek(fp, -1, 1);
//					out(GT, " ");
//				}
//				break;
//			default: report_error(); break;
//			}
//	return;
//}
//bool lookup(char[] c)
//{
//
//}
//int main()
//{
//	FILE* fp = fopen("test.txt", "r");
//	scanner_example(fp);
//}