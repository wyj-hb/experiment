//#include "head_extern1.h"
//void scanner_example(FILE* fp)
//{
//	string s;
//	char ch;
//	ch = fgetc(fp);
//	bool c;
//	while (ch != EOF)
//	{
//		s = "";
//		if (ch == ' ' || ch == '\n' || ch == '\t')
//		{
//			if (ch == '\n')
//			{
//				column++;
//			}
//			ch = fgetc(fp);
//			continue;
//		}
//		else
//		{
//			//���ļ��ж�ȡһ���ַ�,ÿ�ε��ø���ָ���λ��
//			//�ж��ַ��Ƿ�Ϊ��ĸ�ַ�
//			bool is_float = false;
//			bool is_since = false;
//			bool is_num = true;
//			if (isalpha(ch))
//			{
//				s += ch;
//				ch = fgetc(fp);
//				//�ж��Ƿ�����ĸ
//				while (isalnum(ch))
//				{
//					//ѭ��ֱ���ҵ���һ��������ĸ��
//					s += ch;
//					ch = fgetc(fp);
//				}
//				//�����Ǳ�ʶ�����ǹؼ���
//				c = lookup(s);
//				if (c == 0)
//				{
//					if (true)
//					{
//						//�Ǳ�ʶ���ҺϷ�
//						out(ID, s);
//					}
//				}
//				else
//				{
//					//�ǹؼ���
//					out_key(s);
//				}
//			}
//			else
//			{
//				try
//				{
//					char first = ch;
//					if (isdigit(ch))//�ж��Ƿ�������
//					{
//						while (isdigit(ch) || ch == '.' || ch == 'E')
//						{
//							if (ch == '.')
//							{
//								is_float = true;
//								is_num = false;
//								break;
//							}
//							s += ch;
//							if (ch == 'E')
//							{
//								is_num = false;
//								is_since = true;
//								break;
//							}
//							ch = fgetc(fp);
//						}
//						if (is_num)
//						{
//							if (isalnum(ch))
//							{
//								//����һ�������ֿ�ͷ���ַ���
//								ch = loop(fp);
//								cout << "��" + to_string(column) + "�г���:" << endl;
//								string sss ="The identifier cannot begin with a number : ";
//								sss += first;
//								throw MyException(sss);
//							}
//							else
//							{
//								//˵�����ȷ��һ������
//								out(INT, s);
//							}
//						}
//						else if (is_since)
//						{
//							status_four(s, fp, ch);
//						}
//						else
//						{
//
//							status_Three(s, fp, ch);
//						}
//					}
//					else
//					{
//						//��������
//						switch (ch)
//						{
//						case '<':
//							ch = fgetc(fp);
//							if (ch == '=')
//							{
//								//<=
//								ch = fgetc(fp);
//								out(IS, " ");
//							}
//							else if (ch == '>')
//							{
//								//<>
//								ch = fgetc(fp);
//								out(NE, " ");
//							}
//							else if (ch == '<')
//							{
//								//<<
//								ch = fgetc(fp);
//								out(C_OUT, " ");
//							}
//							else
//							{
//								out(LT, " ");
//							}
//							break;
//						case '=':
//							ch = fgetc(fp);
//							out(IS, " "); break;
//						case '>':
//							ch = fgetc(fp);
//							if (ch == '=')
//							{
//								ch = fgetc(fp);
//								out(GE, " ");
//							}
//							else if (ch == '>')
//							{
//								ch = fgetc(fp);
//								out(C_IN, " ");
//							}
//							else
//							{
//								out(GT, " ");
//							}
//							break;
//						case '+':
//							ch = fgetc(fp);
//							if (ch == '+')
//							{
//								ch = fgetc(fp);
//								out(PLUS_PLUS, "");
//							}
//							else
//							{
//								//���ż�
//								out(PL, " ");
//							}
//							break;
//						case '-':
//							//dec dec
//							ch = fgetc(fp);
//							if (ch == '-')
//							{
//								ch = fgetc(fp);
//								out(SUB_SUB, "");
//							}
//							else
//							{
//								//���ż�
//								out(MI, " ");
//							}
//							break;
//						case '*':
//							ch = fgetc(fp);
//							out(MU, " "); break;
//						case '/':
//							ch = fgetc(fp);
//							//����
//							if (ch == '0')
//							{
//								//����������Ϊ0
//								ch = loop(fp);
//								cout << "��" + to_string(column) + "�г���:" << endl;
//								throw MyException("The divisor cannot be 0");
//							}
//							//����ע��
//							else if (ch == '/')
//							{
//								//ע�Ͳ���Ӧ��ɾ��
//								while (ch != '\n' && ch != EOF)
//								{
//									ch = fgetc(fp);
//								}
//							}
//							else
//							{
//								//��ȷ���
//								out(DI, " ");
//							}
//							break;
//						case '{':
//							ch = fgetc(fp);
//							out(L_B, " ");
//							break;
//						case '}':
//							ch = fgetc(fp);
//							out(R_B, " ");
//							break;
//						case '(':
//							ch = fgetc(fp);
//							out(L_P, " ");
//							break;
//						case ')':
//							ch = fgetc(fp);
//							out(R_P, " ");
//							break;
//						case '"':
//						{
//							//���俪ʼ����β�����ַ���,���ֱ�����з�Ҳ�Ҳ����ַ�������Ϊ�Ǵ���,�׳��쳣
//							string sssss = "";
//							ch = fgetc(fp);
//							while (ch != '"' && ch != '\n' && ch != -1)
//							{
//								sssss += ch;
//								ch = fgetc(fp);
//							}
//							if (ch != '"')
//							{
//								ch = loop(fp);
//								cout << "��" + to_string(column) + "�г���:" << endl;
//								throw MyException("The string input is incorrect, and the closing symbol is missing");
//							}
//							else
//							{
//								ch = fgetc(fp);
//								out(STRING, sssss);
//							}
//							break;
//						}
//						case '\n':
//							break;
//						case '.':
//						{
//							status_Three(s, fp, ch);
//						}
//						case ';':
//							out(SEMICOLON, "");
//							ch = fgetc(fp);
//							break;
//						default:
//							ch = loop(fp);
//							string ssss = "Presence is not allowed ";
//							ssss += c;
//							throw MyException(ssss);
//						}
//					}
//				}
//				catch (const MyException& e)
//				{
//					std::cerr << "Catch exception:" << e.what() << std::endl;
//				}
//			}
//		}
//	}
//	return;
//}
//int main()
//{
//	string keyward_src = "keyward_extend1.txt";
//	init_keyword(v, keyward_src);
//	getkey();
//	FILE* p;
//	f_data.open("D:\\����ԭ��ʵ���������\\out_shiyan3.txt", ios::out);
//	p = fopen("shiyan3.txt", "r");
//	scanner_example(p);
//}