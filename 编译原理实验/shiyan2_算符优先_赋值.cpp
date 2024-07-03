//#include<iostream>
//#include<string>
//#include<map>
//#include<fstream>
//#include<vector>  
//#include<stack>
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include "算符优先矩阵.h"
//using namespace std;
//#define MAXSIZE 100
//typedef struct
//{
//	map<char, char> m_next[MAXSIZE];
//	map<char, int> m_index;
//}Matrix;
//unordered_map<string, string> m_p;
//string init_keyword(string src)
//{
//    ifstream file(src);
//    string line;
//    string s;
//    s+="#";
//    while (getline(file, line))
//    {
//        auto index = line.find(',');
//        line = line.substr(1, index - 1);
//        if (line == "INT" || line == "UCON" || line == "SCIENCE_NUM")
//        {
//            s += "i";
//        }
//        else if (line == "PL")
//        {
//            s += "+";
//        }
//        else if (line == "MI")
//        {
//            s += "-";
//        }
//        else if (line == "MU")
//        {
//            s += "*";
//        }
//        else if (line == "DI")
//        {
//            s += "/";
//        }
//        else if (line == "IS")
//        {
//            s += "=";
//        }
//        else if (line == "SEMICOLON")
//        {
//            s += ";";
//        }
//        else if (line == "ID")
//        {
//            s += "V";
//        }
//        else if (line == "L_P")
//        {
//            s += "(";
//        }
//        else if (line == "R_P")
//        {
//            s += ")";
//        }
//    }
//    s += "#";
//    return s;
//}
////判断是否是终结字符
//bool if_end(char c)
//{
//    if (c == 'E' || c == 'T' || c == 'F'||c == 'S'||c == 'V')
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//void init_production()
//{
//    m_p["V=E;"] = "S";
//    m_p["E+T"] = "E";
//    m_p["E-T"] = "E";
//    m_p["T"] = "E";
//    m_p["T*F"] = "T";
//    m_p["T/F"] = "T";
//    m_p["F"] = "T";
//    m_p["(E)"] = "F";
//    m_p["i"] = "F";
//    m_p["h"] = 'V';
//}
//bool matching(string s1,string s2)
//{
//   // 匹配s1和s2是否匹配
//    if (s1.size() != s2.size())
//    {
//        return false;
//    }
//    else
//    {
//        for (int i = 0; i < s1.size(); i++)
//        {
//            //均是非终结
//            if (!if_end(s1[i]) && !if_end(s2[i]))
//            {
//                if (s1[i] == s2[i])
//                {
//                    continue;
//                }
//                else
//                {
//                    return false;
//                }
//            }
//            else if (if_end(s1[i]) && if_end(s2[i]))
//            {
//                continue;
//            }
//            else
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//string replace_s(string s)
//{
//    //查找s可以由哪个式子替换所得,其中终结符的位置必须相同,非终结符位置对应即可
//    for (const auto& pair : m_p)
//    {
//        //匹配
//        if (matching(s, pair.first))
//        {
//            return pair.second;
//        }
//    }
//}
//void char_analyze(string s,Matrix* m)
//{
//    while (s!="#S#")
//    {
//        //上一次<号出现的位置
//        int index = -1;
//        int end_count = 1;
//        for (int i = 0; i < s.size() - 1; i++)
//        {
//            int num = i;
//            while (if_end(s[i+1]) && i < s.size() - 1)
//            {
//                i++;
//            }
//            if (m->m_next[m->m_index[s[num]]][s[i+1]] == '<')
//            {
//                index = num;
//            }
//            else if (m->m_next[m->m_index[s[num]]][s[i + 1]] == '>')
//            {
//                if (index != -1)
//                {
//                    //从这里开始截取字符串
//                    string str = s.substr(index + 1, i-index);
//                    string s_replace = replace_s(str);
//                    cout << "归约子串为:" << str << " " << "归约得到的符号为:" << s_replace << endl;
//                    //替换对应位置的字符
//                    s = s.replace(index + 1, i - index, s_replace);
//                    cout << "当前句型优先关系:" << s << " ";
//                    break;
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            else if (m->m_next[m->m_index[s[num]]][s[i + 1]] == '=')
//            {
//                continue;
//            }
//            else
//            {
//                cout << "error!" << endl;
//                return;
//            }
//        }
//    }
//    cout << endl << "right";
//}
//Matrix* init_mm()
//{
//    auto matrix = new Matrix();
//    matrix->m_index['('] = 0;
//    matrix->m_next[0]['('] = '<';
//    matrix->m_next[0]['i'] = '<';
//    matrix->m_next[0]['*'] = '<';
//    matrix->m_next[0]['+'] = '<';
//    matrix->m_next[0]['-'] = '<';
//    matrix->m_next[0]['/'] = '<';
//    matrix->m_next[0][')'] = '=';
//    //i
//    matrix->m_index['i'] = 1;
//    matrix->m_next[1]['*'] = '>';
//    matrix->m_next[1]['+'] = '>';
//    matrix->m_next[1][')'] = '>';
//    matrix->m_next[1]['#'] = '>';
//    matrix->m_next[1]['-'] = '>';
//    matrix->m_next[1]['/'] = '>';
//    matrix->m_next[1][';'] = '>';
//    //*
//    matrix->m_index['*'] = 2;
//    matrix->m_next[2]['('] = '<';
//    matrix->m_next[2]['i'] = '<';
//    matrix->m_next[2]['*'] = '>';
//    matrix->m_next[2]['+'] = '>';
//    matrix->m_next[2][')'] = '>';
//    matrix->m_next[2]['#'] = '>';
//    matrix->m_next[2]['-'] = '>';
//    matrix->m_next[2]['/'] = '>';
//    matrix->m_next[2][';'] = '>';
//   //+
//    matrix->m_index['+'] = 3;
//    matrix->m_next[3]['('] = '<';
//    matrix->m_next[3]['i'] = '<';
//    matrix->m_next[3]['*'] = '<';
//    matrix->m_next[3]['+'] = '>';
//    matrix->m_next[3][')'] = '>';
//    matrix->m_next[3]['#'] = '>';
//    matrix->m_next[3]['-'] = '<';
//    matrix->m_next[3]['/'] = '<';
//    matrix->m_next[3][';'] = '>';
//     //)
//    matrix->m_index[')'] = 4;
//    matrix->m_next[4]['*'] = '>';
//    matrix->m_next[4]['+'] = '>';
//    matrix->m_next[4][')'] = '>';
//    matrix->m_next[4]['#'] = '>';
//    matrix->m_next[4]['-'] = '>';
//    matrix->m_next[4]['/'] = '>';
//    matrix->m_next[4][';'] = '>';
//    //#
//    matrix->m_index['#'] = 5;
//    matrix->m_next[5]['='] = '<';
//    //=
//    matrix->m_index['='] = 6;
//    matrix->m_next[6][';'] = '=';
//    matrix->m_next[6]['('] = '<';
//    matrix->m_next[6]['i'] = '<';
//    matrix->m_next[6]['*'] = '<';
//    matrix->m_next[6]['+'] = '<';
//    matrix->m_next[6]['-'] = '<';
//    matrix->m_next[6]['/'] = '<';
//    //;
//    matrix->m_index[';'] = 7;
//    matrix->m_next[7]['#'] = '>';
//   // h
//    matrix->m_index['h'] = 8;
//    matrix->m_next[8]['='] = '>';
//    //-
//    matrix->m_index['-'] = 9;
//    matrix->m_next[9]['('] = '<';
//    matrix->m_next[9]['i'] = '<';
//    matrix->m_next[9]['*'] = '<';
//    matrix->m_next[9]['+'] = '>';
//    matrix->m_next[9][')'] = '>';
//    matrix->m_next[9]['#'] = '>';
//    matrix->m_next[9]['-'] = '<';
//    matrix->m_next[9]['/'] = '<';
//    matrix->m_next[9][';'] = '<';
//    // /
//    matrix->m_index['/'] = 10;
//    matrix->m_next[10]['('] = '<';
//    matrix->m_next[10]['i'] = '<';
//    matrix->m_next[10]['*'] = '>';
//    matrix->m_next[10]['+'] = '>';
//    matrix->m_next[10][')'] = '>';
//    matrix->m_next[10]['#'] = '>';
//    matrix->m_next[10]['-'] = '>';
//    matrix->m_next[10]['/'] = '>';
//    matrix->m_next[10][';'] = '>';
//    return matrix;
//}
//int main()
//{
//    auto matrix = init_mm();
//    init_production();
//    string src = "D:\\编译原理实验输出数据\\out_shiyan2_test_data.txt";
//    auto str = init_keyword(src);
//    cout <<"当前句型优先关系:"<<str << " ";
//    char_analyze(str,matrix);
//}