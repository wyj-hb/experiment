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
////ɨ���ı�
//void scanner_example(FILE* fp)
//{
//	char ch; 
//	int i, c;
//	//���ļ��ж�ȡһ���ַ�,ÿ�ε��ø���ָ���λ��
//	ch = fgetc(fp);
//	//�ж��ַ��Ƿ�Ϊ��ĸ�ַ�
//	if (isalpha(ch))
//	{
//		//����һ����ĸ��¼��TOKEN������
//		TOKEN[0] = ch;
//		ch = fgetc(fp); 
//		i = 1;
//		//�ж��Ƿ�����ĸ
//		while (isalnum(ch))
//		{
//			//ѭ��ֱ���ҵ���һ��������ĸ��
//			TOKEN[i] = ch; 
//			i++;
//			ch = fgetc(fp);
//		}
//		//��ʶ�ַ����Ľ�β
//		TOKEN[i] = '��0';
//		//��ָ�뷵����һ��λ��
//		fseek(fp, -1, 1); 
//		//�ж�TOKEN�ǹؼ���/��ʶ��
//		c = lookup(TOKEN);
//		if (c == 0)
//		{
//			//�Ǳ�ʶ��
//			out(ID, TOKEN);
//		}
//		else
//		{
//			//�ǹؼ���
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
//			TOKEN[i] = '��0'��
//				fseek(fp, -1, 1);
//			out(INT, TOKEN);
//		}
//		else
//			switch (ch)
//			{
//			case �䣼��: ch = fgetc(fp);
//				if (ch == �� = ��)out(LE, " ");
//				else if (ch == �䣾��) out(NE, " ");
//				else
//				{
//					fseek(fp, -1, 1);
//					out(LT, " ");
//				}
//				break;
//			case �� = ��: out(EQ, " "); break;
//			case �䣾��: ch = fgetc(fp);
//				if (ch == �� = ��)out(GE, " ");
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