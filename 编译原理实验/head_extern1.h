#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<vector>  
#include <exception>
#include <sstream>
using namespace std;
#pragma once
# define ID 6
# define INT 7
# define LT 8
# define LE 9
# define EQ 10
# define NE 11
# define GT 12
# define GE 13
# define IS 14
# define PL 15//+
# define MI 16//-
# define MU 17//*
# define DI 18///
#define UCON 19
#define STRING 20
#define CHAR_C 21
#define PLUS_PLUS 22
#define SUB_SUB 23
#define SCIENCE_NUM 24
#define SEMICOLON 25
#define C_IN 26
#define C_OUT 27
#define L_P 28
#define R_P 29
#define L_B 30
#define R_B 31
#define BEGIN 1
#define END 2
#define IF 3
#define THEN 4
#define ELSE 5
#define WHILE 32
#define DO 33
extern bool lookup(string s);
extern void out(int, string s);
extern void report_error();
extern void out_key(string s);
extern void report_error(char c);
extern double revert(string s);
multimap<string, string> m;//存储二元组
vector<string> v;//关键字容器
map<int, string> mm;
ofstream f_data;
int column = 1;
//自定义异常类,用来处理标识符命名的不规范错误
class MyException : public exception
{
private:
	std::string message;
public:
	MyException(const std::string& msg) : message(msg)
	{
	}
	//提供异常消息
	virtual const char* what() const noexcept override {
		return message.c_str();
	}
};
extern char loop(FILE* fp);
//扫描文本
void getkey()
{
	mm.insert(pair<int, string>(6, "ID"));
	mm.insert(pair<int, string>(7, "INT"));
	mm.insert(pair<int, string>(8, "LT"));
	mm.insert(pair<int, string>(9, "LE"));
	mm.insert(pair<int, string>(10, "EQ"));
	mm.insert(pair<int, string>(11, "NE"));
	mm.insert(pair<int, string>(12, "GT"));
	mm.insert(pair<int, string>(13, "GE"));
	mm.insert(pair<int, string>(14, "IS"));
	mm.insert(pair<int, string>(15, "PL"));
	mm.insert(pair<int, string>(16, "MI"));
	mm.insert(pair<int, string>(17, "MU"));
	mm.insert(pair<int, string>(18, "DI"));
	mm.insert(pair<int, string>(19, "UCON"));
	mm.insert(pair<int, string>(20, "STRING"));
	mm.insert(pair<int, string>(21, "CHAR_C"));
	mm.insert(pair<int, string>(22, "PLUS_PLUS"));
	mm.insert(pair<int, string>(23, "SUB_SUB"));
	mm.insert(pair<int, string>(24, "SCIENCE_NUM"));
	mm.insert(pair<int, string>(25, "SEMICOLON"));
	mm.insert(pair<int, string>(26, "C_IN"));
	mm.insert(pair<int, string>(27, "C_OUT"));
	mm.insert(pair<int, string>(28, "L_P"));
	mm.insert(pair<int, string>(29, "R_P"));
	mm.insert(pair<int, string>(30, "L_B"));
	mm.insert(pair<int, string>(31, "R_B"));
	mm.insert(pair<int, string>(32, "WHILE"));
	mm.insert(pair<int, string>(33, "DO"));
	mm.insert(pair<int, string>(1, "BEGIN"));
	mm.insert(pair<int, string>(2, "END"));
	mm.insert(pair<int, string>(3, "IF"));
	mm.insert(pair<int, string>(4, "THEN"));
	mm.insert(pair<int, string>(5, "ELSE"));
}
bool is_enchar(char c)
{
	if (10 > 5)
	{

	}
	if(c <= 'z' && c >= 'a')
	{
		return false;
	}
	else if (c <= 'Z' && c >= 'A')
		return false;
	else if (c <= '9' && c >= '0')
	{
		return true;
	}
	else
	{
		return true;
	}
}
char loop(FILE* fp)
{
	char ch = fgetc(fp);
	while (ch != ' ' && ch != -1 && ch != ';')
	{
		ch = fgetc(fp);
	}
	return ch;
}
//判断s是关键字还是标识符
bool lookup(string s)
{
	//判断s是关键字还是标识符
	if (find(v.begin(), v.end(), s) != v.end())
	{
		//是标识符
		return true;
	}
	else
	{
		return false;
	}
}
void string_upper(string& s)
{
	for (auto& c : s)
	{
		c -= 32;
	}
}
void init_keyword(vector<string>& v, string src)
{
	//初始化关键字容器
	ifstream file(src);
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string str;
		while (ss >> str)
		{
			v.push_back(str);
		}
	}
}
//
double revert_front(string s)
{
	int index = s.find(".");
	double sum = 0;
	if (index != string::npos)
	{
		int num1 = index;
		
		//存在小数点
		for (int i = 0; i < index; i++)
		{
			sum += (s[i] - '0') * pow(10, num1 - 1);
			num1--;
		}
		int num2 = 1;
		for (int i = index + 1; i < s.size(); i++)
		{
			sum += (s[i] - '0') * pow(0.1, num2);
			num2++;
		}
	}
	else
	{
		int num = s.size();
		//不存在小数点
		for (int i = 0; i < s.size(); i++)
		{
			sum += (s[i] - '0') * pow(10, num - 1);
			num--;
		}
	}
	return sum;
}
double revert_back(string s)
{
	int index_plus = s.find("+");
	int index_sub = s.find("-");

	if (index_plus == string::npos && index_sub == string::npos)
	{
		//一个数字,交给revert_front处理
		double back_num = revert_front(s);
		//默认是+
		back_num = pow(10, back_num);
		return back_num;
	}
	//存在+/-
	else
	{
		//存在+号,
		double sum = 0;
		
		//根据加减号
		if (index_plus != string::npos)
		{
			string str = s.substr(index_plus + 1, s.size() - 1);
			double num = revert_front(str);
			//加
			auto num_return = pow(10, num);
			return num_return;
		}
		else
		{
			string str = s.substr(index_sub + 1, s.size() - 1);
			double num = revert_front(str);
			auto num_return  = pow(0.1, num);
			return num_return;
		}
	}
}
double revert(string str)
{
	double sum = 0;
	double param_1;
	double param_2;
	int index = str.find("E");
	string s_num1 = str.substr(0, index);
	string s_num2 = str.substr(index + 1, str.length());
	double num_1 = revert_front(s_num1);
	double num_2 = revert_back(s_num2);
	sum = num_1 * num_2;
	return sum;
}
//将内容按照二元组的形式存储
void out(int type, string s)
{
	//选择使用map进行存储
	string str = mm[type];
	m.insert(pair<string, string>(str, s));
	if (type == 24)
	{
		//是科学计数法的数字
		double ssss = revert(s);
		cout << "(" + str + ","<< ssss<<")" << endl;
		f_data << "(" + str + ","<<ssss<< ")" << endl;
	}
	else
	{
		cout << "(" + str + "," + s + ")" << endl;
		f_data << "(" + str + "," + s + ")" << endl;
	}
}
void status_four(string s,FILE* fp,char &ch)
{
	ch = fgetc(fp);
	//此时有两条路,分别为+-或者纯输出d
	if (ch == '+' || ch == '-')
	{
		s += ch;
		ch = fgetc(fp);
		//接下来至少存在一个整数
		if (!isdigit(ch))
		{
			ch = loop(fp);
			cout << "第" + to_string(column) + "行出错:" << endl;
			throw MyException("Scientific notation is malformed");
		}
		while (isdigit(ch))
		{
			s += ch;
			ch = fgetc(fp);
		}
		if (!isalpha(ch))
		{
			//格式无误
			out(SCIENCE_NUM, s);
		}
		else
		{
			ch = loop(fp);
			cout << "第" + to_string(column) + "行出错:" << endl;
			throw MyException("Scientific notation is malformed");
		}
	}
	else if (isdigit(ch))
	{
		s += ch;
		ch = fgetc(fp);
		while (isdigit(ch))
		{
			s += ch;
			ch = fgetc(fp);
		}
		if (ch == ' ' || ch == '\n' || ch == -1)
		{
			//格式无误
			out(SCIENCE_NUM, s);
		}
		else
		{
			ch = loop(fp);
			s = "";
			cout << "第" + to_string(column) + "行出错:" << endl;
			throw MyException("Scientific notation is malformed");
		}
	}
	else
	{
		ch = loop(fp);
		s = "";
		cout << "第" + to_string(column) + "行出错:" << endl;
		throw MyException("Scientific notation is malformed");
	}
}
void status_Three(string s, FILE* fp, char& ch)
{
	//小数.
	//是以.开头的数
	bool is_since = false;
	s += ch;
	ch = fgetc(fp);
	//至少存在一个数字,否则抛出异常
	if (!isdigit(ch))
	{
		cout << "第" + to_string(column) + "行出错:" << endl;
		throw MyException("Numbers are formatted incorrectly");
	}
	else
	{
		//要么出现E要么出现d,否则报错
		while (ch != ' ' && ch != -1 && ch != '\n')
		{
			s += ch;
			if (ch == 'E')
			{
				is_since = true;
				break;
			}
			if (!isdigit(ch))
			{
				//不是数字则为错误
				ch = loop(fp);
				cout << "第" + to_string(column) + "行出错:" << endl;
				throw MyException("Numbers are formatted incorrectly");
			}
			ch = fgetc(fp);
		}
		if (is_since)
		{
			status_four(s, fp, ch);
		}
		else
		{
			out(UCON, s);
		}
	}
}
void out_key(string s)
{
	m.insert(pair<string, string>(s, " "));
	string_upper(s);
	cout << "(" + s + ",  )" << endl;
	f_data << "(" + s + ",  )" << endl;
}
