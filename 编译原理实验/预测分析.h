#pragma once
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>  
#include<stack>
#include "first_follow.h"
#define MAXSIZE 100
using namespace std;
typedef struct
{
    map<char, string> m_next[MAXSIZE];
    map<char, int> m_index;
}Matrix;
//输入文法,构造follow集和first集
vector<char> init_keyword(string src)
{
    vector<char> v;
    ifstream file(src);
    string line;
    while (getline(file, line))
    {
        auto index = line.find(',');
        line = line.substr(1, index - 1);
        if (line == "INT" || line == "UCON" || line == "SCIENCE_NUM")
        {
            v.push_back('i');
        }
        else if (line == "ID")
        {
            v.push_back('h');
        }
        else if (line == "PL")
        {
            v.push_back('+');
        }
        else if (line == "MI")
        {
            v.push_back('-');
        }
        else if (line == "MU")
        {
            v.push_back('*');
        }
        else if (line == "DI")
        {
            v.push_back('/');
        }
        else if (line == "IS")
        {
            v.push_back('=');
        }
        else if (line == "SEMICOLON")
        {
            v.push_back(';');
        }
    }
    v.push_back('#');
    return v;
}
Matrix* init_mm()
{
    conduct_Matrix();
    auto matrix = new Matrix();
    int count = 0;
    for (auto c : gather_end)
    {
        matrix->m_index[c] = count;
        //产生式
        auto PRo = v_production[a->K_index[c]];
        //将产生式按照|分开
        vector<string> v;
        //切割字符串,按照|分隔
        split(PRo, "|", v);
        //vv是每一个产生式
        for (int j = 0;j<v.size();j++)
        {
            //一个产生式对应一个vector<string>
            //cc相当于每一个字母
            for (auto ccc : a->m_first[a->K_index[c]][j])
            {
                if (v[j] == "ε")
                {
                    //寻找follow集合
                    for (auto cccc : a->m_follow[a->K_index[c]])
                    {
                        matrix->m_next[count][cccc] = "ε";
                    }
                    break;
                }
                else
                {
                    //对于每一个产生式,对应着不同的FIRST集合,产生式的顺序与
                    matrix->m_next[count][ccc] = v[j];
                }
            }
           
        }
        count++;
    }
    return matrix;
}
//
//Matrix* init_mm()
//{
//    auto matrix = new Matrix();
//    //E
//    matrix->m_index['E'] = 0;
//    matrix->m_next[0]['i'] = "TG";
//    matrix->m_next[0]['('] = "TG";
//    //G
//    matrix->m_index['G'] = 1;
//    matrix->m_next[1]['+'] = "ATG";
//    matrix->m_next[1]['-'] = "ATG";
//    matrix->m_next[1][')'] = "ε";
//    //matrix->m_next[1]['#'] = "ε";
//    matrix->m_next[1][';'] = "ε";
//    //T
//    matrix->m_index['T'] = 2;
//    matrix->m_next[2]['i'] = "FH";
//    matrix->m_next[2]['('] = "FH";
//    //H
//    matrix->m_index['H'] = 3;
//    matrix->m_next[3]['+'] = "ε";
//    matrix->m_next[3]['-'] = "ε";
//    matrix->m_next[3]['*'] = "MFH";
//    matrix->m_next[3]['/'] = "MFH";
//    matrix->m_next[3]['('] = "ε";
//    matrix->m_next[3][')'] = "ε";
//    //matrix->m_next[3]['#'] = "ε";
//    matrix->m_next[3][';'] = "ε";
//    //F
//    matrix->m_index['F'] = 4;
//    matrix->m_next[4]['i'] = "i";
//    matrix->m_next[4]['('] = "(E)";
//    //A
//    matrix->m_index['A'] = 5;
//    matrix->m_next[5]['+'] = "+";
//    matrix->m_next[5]['-'] = "-";
//    //M
//    matrix->m_index['M'] = 6;
//    matrix->m_next[6]['*'] = "*";
//    matrix->m_next[6]['/'] = "/";
//    //S
//    matrix->m_index['S'] = 7;
//    matrix->m_next[7]['h'] = "V=E;";
//    //V
//    matrix->m_index['V'] = 8;
//    matrix->m_next[8]['h'] = "h";
//    return matrix;
//}

void show_nowstack(stack<char> s)
{
    cout << "当前分析栈中元素为:";
    string ss = "";
    while (!s.empty())
    {
        string temp = { s.top() };
        s.pop();
        ss += temp;
    }
    reverse(ss.begin(), ss.end());
    for (auto c : ss)
    {
        cout << c;
    }
    cout << "\t\t";
}
void show_string(vector<char> v, int index)
{
    cout << "当前余留输入串为:";
    for (int i = index; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}
void control_out(stack<char> s, Matrix* m, vector<char> v)
{
    int count = 0;
    //开始分析
    while (s.top() != '#')
    {
        show_nowstack(s);
        show_string(v, count);
        if (s.top() == v[count])
        {
            if (v[count] != '#')
            {
                count++;
            }
            s.pop();
        }
        else
        {
            if (m->m_next[m->m_index[s.top()]][v[count]] != "")
            {
                auto str = m->m_next[m->m_index[s.top()]][v[count]];
                if (str == "ε")
                {
                    s.pop();
                }
                else
                {
                    s.pop();
                    //倒叙入栈
                    reverse(str.begin(), str.end());
                    for (auto c : str)
                    {
                        s.push(c);
                    }
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
    }
    show_nowstack(s);
    show_string(v, count);
    cout << "right" << endl;
}