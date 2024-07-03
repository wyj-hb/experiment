//#include<iostream>
//#include<string>
//#include<map>
//#include<fstream>
//#include<sstream>
//#include<vector>  
//#include <exception>
//using namespace std;
//# define ID 6
//# define INT 7
//# define LT 8
//# define LE 9
//# define EQ 10
//# define NE 11
//# define GT 12
//# define GE 13
//# define IS 14
//# define PL 15
//# define MI 16
//# define MU 17
//# define DI 18
//#define UCON 19
//extern bool lookup(string s);
//extern void out(int,string s);
//extern void report_error();
//extern void out_key(string s);
////extern bool is_exception(string s);
//extern void report_error(char c);
//multimap<string, string> m;//存储二元组
//vector<string> v;//关键字容器
//map<int, string> mm;
//ofstream f_data;
////自定义异常类,用来处理标识符命名的不规范错误
//class MyException : public exception 
//{
//private:
//	std::string message;
//public:
//	MyException(const std::string& msg) : message(msg)
//	{
//
//	}
//	// 2. 提供异常消息
//	virtual const char* what() const noexcept override {
//		return message.c_str();
//	}
//};
////扫描文本
//void getkey()
//{
//	mm.insert(pair<int, string>(6,"ID"));
//	mm.insert(pair<int, string>(7, "INT"));
//	mm.insert(pair<int, string>(8, "LT"));
//	mm.insert(pair<int, string>(9, "LE"));
//	mm.insert(pair<int, string>(10, "EQ"));
//	mm.insert(pair<int, string>(11, "NE"));
//	mm.insert(pair<int, string>(12, "GT"));
//	mm.insert(pair<int, string>(13, "GE"));
//	mm.insert(pair<int, string>(14, "IS"));
//	mm.insert(pair<int, string>(15, "PL"));
//	mm.insert(pair<int, string>(16, "MI"));
//	mm.insert(pair<int, string>(17, "MU"));
//	mm.insert(pair<int, string>(18, "DI"));
//	mm.insert(pair<int, string>(19, "UCON"));
//}
//void scanner_example(FILE* fp)
//{
//	string s;
//	char ch;
//	ch = fgetc(fp);
//	bool c;
//	bool is_out = false;
//	while (ch != EOF)
//	{
//		s = "";
//		if (ch == ' ')
//		{
//			ch = fgetc(fp);
//			continue;
//		}
//		else
//		{
//			//从文件中读取一个字符,每次调用更新指针的位置
//			//判断字符是否为字母字符
//			bool is_float = false;
//			if (isalpha(ch))
//			{
//				//将第一个字母记录到TOKEN数组中
//				s += ch;
//				ch = fgetc(fp);
//				//判断是否是字母
//				while (isalnum(ch))
//				{
//					//循环直到找到第一个不是字母的
//					s += ch;
//					ch = fgetc(fp);
//				}
//				//将指针返回上一个位置
//				//fseek(fp, -1, 1);
//				//判断TOKEN是关键字/标识符
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
//				char first = ch;
//				if (isdigit(ch))//判断是否是数字
//				{
//					s += ch;
//					ch = fgetc(fp);
//					while (isdigit(ch) || ch == '.')
//					{
//						if (ch == '.')
//						{
//							is_float = true;
//						}
//						s += ch;
//						ch = fgetc(fp);
//					}
//					if (ch == ' ')
//					{
//						//说明这的确是一个数字
//						//fseek(fp, -1, 1);
//						if (is_float)
//						{
//							out(UCON, s);
//						}
//						else
//						{
//							out(INT, s);
//						}
//					}
//					else
//					{
//						//这是一个以数字开头的字符串
//						try {
//							string s = "The identifier cannot begin with a number:";
//							s += first;
//							throw MyException(s);
//						}
//						catch (const MyException& e)
//						{  // 4. 捕获自定义异常
//							std::cerr << "Caught exception:" << e.what() << std::endl;
//						}
//						while (ch != ' ' && ch != -1)
//						{
//							ch = fgetc(fp);
//						}
//					}
//				}
//				else
//				{
//					//不是数字
//					switch (ch)
//					{
//					case '<':
//						ch = fgetc(fp);
//						if (ch == '=')
//						{
//							//<=
//							ch = fgetc(fp);
//							out(IS, " ");
//						}
//						else if (ch == '>')
//						{
//							//<>
//							ch = fgetc(fp);
//							out(NE, " ");
//						}
//						else
//						{
//							//fseek(fp, -1, 1);
//							out(LT, " ");
//						}
//						break;
//					case '=':
//						ch = fgetc(fp);
//						out(IS, " "); break;
//					case '>':
//						ch = fgetc(fp);
//						if (ch == '=')
//						{
//							//>=
//							ch = fgetc(fp);
//							out(GE, " ");
//						}
//						else
//						{
//							out(GT, " ");
//						}
//						break;
//					case '\n':
//						ch = fgetc(fp);
//						is_out = true;
//					default:
//						report_error(ch);
//						while (ch != ' ' && ch != -1)
//						{
//							ch = fgetc(fp);
//						}
//						break;
//					}
//				}
//			}
//		}
//		
//	}
//	return;
//}
//void report_error(char c)
//{
//	try {
//		string s = "Presence is not allowed ";
//		s += c;
//		throw MyException(s);
//	}
//	catch (const MyException& e)
//	{  // 4. 捕获自定义异常
//		std::cerr << "Caught exception:" << e.what() << std::endl;
//	}
//}
////判断s是关键字还是标识符
//bool lookup(string s)
//{
//	//判断s是关键字还是标识符
//	if (find(v.begin(), v.end(), s) != v.end())
//	{
//		//是标识符
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//void string_upper(string& s)
//{
//	for (auto& c : s)
//	{
//		c -= 32;
//	}
//}
//void init_keyword(vector<string> &v,string src)
//{
//	//初始化关键字容器
//	ifstream file(src);
//	string line;
//	while (getline(file, line))
//	{
//		stringstream ss(line);
//		string str;
//		while (ss >> str)
//		{
//			v.push_back(str);
//		}
//	}
//	file.close();
//}
////将内容按照二元组的形式存储
//void out(int type,string s)
//{
//	//选择使用map进行存储
//	string str = mm[type];
//	m.insert(pair<string, string>(str, s));
//	cout << "(" +str+","+ s + ")" << endl;
//	f_data<< "(" + str + "," + s + ")" << endl;
//}
//void out_key(string s)
//{
//	m.insert(pair<string, string>(s," "));
//	string_upper(s);
//	cout << "(" + s + ",  )" << endl;
//	f_data << "(" + s + ",  )" << endl;
//}
//int main()
//{
//	string keyward_src = "keyward_basic.txt";
//	init_keyword(v,keyward_src);
//	getkey();
//	FILE* p;
//	f_data.open("D:\\编译原理实验输出数据\\basic_data", ios::out);
//	p = fopen("error_data_basic.txt","r");
//	scanner_example(p);
//}