#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>  
#include<stack>
#define MAXSIZE 100
using namespace std;
typedef struct
{
    map<char, string> m_next[MAXSIZE];
    map<char, int> m_index;
}Matrix;

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
    }
    v.push_back('#');
    return v;
}
Matrix* init_mm()
{
    auto matrix = new Matrix();
    //E
    matrix->m_index['E'] = 0;
    matrix->m_next[0]['i'] = "TG";
    matrix->m_next[0]['('] = "TG";
    //G
    matrix->m_index['G'] = 1;
    matrix->m_next[1]['+'] = "ATG";
    matrix->m_next[1]['-'] = "ATG";
    matrix->m_next[1][')'] = "ε";
    matrix->m_next[1]['#'] = "ε";
    //T
    matrix->m_index['T'] = 2;
    matrix->m_next[2]['i'] = "FH";
    matrix->m_next[2]['('] = "FH";
    //H
    matrix->m_index['H'] = 3;
    matrix->m_next[3]['+'] = "ε";
    matrix->m_next[3]['-'] = "ε";
    matrix->m_next[3]['*'] = "MFH";
    matrix->m_next[3]['/'] = "MFH";
    matrix->m_next[3]['('] = "ε";
    matrix->m_next[3][')'] = "ε";
    matrix->m_next[3]['#'] = "ε";
    //F
    matrix->m_index['F'] = 4;
    matrix->m_next[4]['i'] = "i";
    matrix->m_next[4]['('] = "(E)";
    //A
    matrix->m_index['A'] = 5;
    matrix->m_next[5]['+'] = "+";
    matrix->m_next[5]['-'] = "-";
    //M
    matrix->m_index['M'] = 6;
    matrix->m_next[6]['*'] = "*";
    matrix->m_next[6]['/'] = "/";
    return matrix;
}

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

