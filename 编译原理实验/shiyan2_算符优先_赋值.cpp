//#include<iostream>
//#include<string>
//#include<map>
//#include<fstream>
//#include<vector>  
//#include<stack>
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include "������Ⱦ���.h"
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
////�ж��Ƿ����ս��ַ�
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
//   // ƥ��s1��s2�Ƿ�ƥ��
//    if (s1.size() != s2.size())
//    {
//        return false;
//    }
//    else
//    {
//        for (int i = 0; i < s1.size(); i++)
//        {
//            //���Ƿ��ս�
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
//    //����s�������ĸ�ʽ���滻����,�����ս����λ�ñ�����ͬ,���ս��λ�ö�Ӧ����
//    for (const auto& pair : m_p)
//    {
//        //ƥ��
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
//        //��һ��<�ų��ֵ�λ��
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
//                    //�����￪ʼ��ȡ�ַ���
//                    string str = s.substr(index + 1, i-index);
//                    string s_replace = replace_s(str);
//                    cout << "��Լ�Ӵ�Ϊ:" << str << " " << "��Լ�õ��ķ���Ϊ:" << s_replace << endl;
//                    //�滻��Ӧλ�õ��ַ�
//                    s = s.replace(index + 1, i - index, s_replace);
//                    cout << "��ǰ�������ȹ�ϵ:" << s << " ";
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
//    string src = "D:\\����ԭ��ʵ���������\\out_shiyan2_test_data.txt";
//    auto str = init_keyword(src);
//    cout <<"��ǰ�������ȹ�ϵ:"<<str << " ";
//    char_analyze(str,matrix);
//}