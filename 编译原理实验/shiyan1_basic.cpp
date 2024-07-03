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
//multimap<string, string> m;//�洢��Ԫ��
//vector<string> v;//�ؼ�������
//map<int, string> mm;
//ofstream f_data;
////�Զ����쳣��,���������ʶ�������Ĳ��淶����
//class MyException : public exception 
//{
//private:
//	std::string message;
//public:
//	MyException(const std::string& msg) : message(msg)
//	{
//
//	}
//	// 2. �ṩ�쳣��Ϣ
//	virtual const char* what() const noexcept override {
//		return message.c_str();
//	}
//};
////ɨ���ı�
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
//			//���ļ��ж�ȡһ���ַ�,ÿ�ε��ø���ָ���λ��
//			//�ж��ַ��Ƿ�Ϊ��ĸ�ַ�
//			bool is_float = false;
//			if (isalpha(ch))
//			{
//				//����һ����ĸ��¼��TOKEN������
//				s += ch;
//				ch = fgetc(fp);
//				//�ж��Ƿ�����ĸ
//				while (isalnum(ch))
//				{
//					//ѭ��ֱ���ҵ���һ��������ĸ��
//					s += ch;
//					ch = fgetc(fp);
//				}
//				//��ָ�뷵����һ��λ��
//				//fseek(fp, -1, 1);
//				//�ж�TOKEN�ǹؼ���/��ʶ��
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
//				char first = ch;
//				if (isdigit(ch))//�ж��Ƿ�������
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
//						//˵�����ȷ��һ������
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
//						//����һ�������ֿ�ͷ���ַ���
//						try {
//							string s = "The identifier cannot begin with a number:";
//							s += first;
//							throw MyException(s);
//						}
//						catch (const MyException& e)
//						{  // 4. �����Զ����쳣
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
//					//��������
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
//	{  // 4. �����Զ����쳣
//		std::cerr << "Caught exception:" << e.what() << std::endl;
//	}
//}
////�ж�s�ǹؼ��ֻ��Ǳ�ʶ��
//bool lookup(string s)
//{
//	//�ж�s�ǹؼ��ֻ��Ǳ�ʶ��
//	if (find(v.begin(), v.end(), s) != v.end())
//	{
//		//�Ǳ�ʶ��
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
//	//��ʼ���ؼ�������
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
////�����ݰ��ն�Ԫ�����ʽ�洢
//void out(int type,string s)
//{
//	//ѡ��ʹ��map���д洢
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
//	f_data.open("D:\\����ԭ��ʵ���������\\basic_data", ios::out);
//	p = fopen("error_data_basic.txt","r");
//	scanner_example(p);
//}