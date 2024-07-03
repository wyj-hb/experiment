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
//			//从文件中读取一个字符,每次调用更新指针的位置
//			//判断字符是否为字母字符
//			bool is_float = false;
//			bool is_since = false;
//			bool is_num = true;
//			if (isalpha(ch))
//			{
//				s += ch;
//				ch = fgetc(fp);
//				//判断是否是字母
//				while (isalnum(ch))
//				{
//					//循环直到找到第一个不是字母的
//					s += ch;
//					ch = fgetc(fp);
//				}
//				//查找是标识符还是关键字
//				c = lookup(s);
//				if (c == 0)
//				{
//					if (true)
//					{
//						//是标识符且合法
//						out(ID, s);
//					}
//				}
//				else
//				{
//					//是关键字
//					out_key(s);
//				}
//			}
//			else
//			{
//				try
//				{
//					char first = ch;
//					if (isdigit(ch))//判断是否是数字
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
//								//这是一个以数字开头的字符串
//								ch = loop(fp);
//								cout << "第" + to_string(column) + "行出错:" << endl;
//								string sss ="The identifier cannot begin with a number : ";
//								sss += first;
//								throw MyException(sss);
//							}
//							else
//							{
//								//说明这的确是一个数字
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
//						//不是数字
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
//								//符号加
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
//								//符号加
//								out(MI, " ");
//							}
//							break;
//						case '*':
//							ch = fgetc(fp);
//							out(MU, " "); break;
//						case '/':
//							ch = fgetc(fp);
//							//除法
//							if (ch == '0')
//							{
//								//除数不可以为0
//								ch = loop(fp);
//								cout << "第" + to_string(column) + "行出错:" << endl;
//								throw MyException("The divisor cannot be 0");
//							}
//							//单行注释
//							else if (ch == '/')
//							{
//								//注释部分应该删除
//								while (ch != '\n' && ch != EOF)
//								{
//									ch = fgetc(fp);
//								}
//							}
//							else
//							{
//								//正确输出
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
//							//从其开始到结尾都是字符串,如果直到换行符也找不到字符串则认为是错误,抛出异常
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
//								cout << "第" + to_string(column) + "行出错:" << endl;
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
//	f_data.open("D:\\编译原理实验输出数据\\out_shiyan3.txt", ios::out);
//	p = fopen("shiyan3.txt", "r");
//	scanner_example(p);
//}