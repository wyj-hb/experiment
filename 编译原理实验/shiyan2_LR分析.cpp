#include<iostream>
#include<math.h>
#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include<map>
#include<sstream>
#include<stack>
#include <iomanip>
#define MAXSIZE 1000
using namespace std;
typedef struct
{
    //char�ҵ���Ӧindex���ַ���
    map<char, string> m_next[MAXSIZE];
}Matrix;
typedef struct
{
    //������޷������Ļ�����ֵ��
    string value;
    //��Ӧ������,��������ִ����Ӧ����
    string type;
    //�����ڷ���ջ�еķ���
    char label;
}element;
vector<string> production;
stringstream ss;
//���ÿ�����ս����Ӧ��ֵ
map<string, string> key_value;
vector<string> repeat_replace{ "A","C","D","G","I","J","K","Z","L","M","N"};
void init_production(vector<string> &v)
{
    v.push_back("S'->S");
    v.push_back("S->wBdS");
    v.push_back("S->iBeS");
    v.push_back("S->iB");
    v.push_back("S->H");
    v.push_back("B->b");
    v.push_back("B->G");
    v.push_back("G->V>V");
    v.push_back("G->V<V");
    v.push_back("H->V=E;");
    v.push_back("E->T");
    v.push_back("E->E+T");
    v.push_back("E->E-T");
    v.push_back("T->F");
    v.push_back("T->T*F");
    v.push_back("F->z");
    v.push_back("F->(E)");
    v.push_back("V->h");
    v.push_back("T->T/F"); 
}
Matrix* m = new Matrix();
vector<vector<element>> init_keyword(string src)
{
    ifstream file(src);
    string line;
    vector<vector<element>> s(10);
    int index = 0;
    //string s;
    while (getline(file, line))
    {
        auto index_num = line.find(',');
        string str = line;
        line = line.substr(1, index_num - 1);
        element e;
        if (line == "INT" || line == "UCON")
        {
            e.label = 'z';
            e.type = line;
            //�ҵ� )
            auto index_a = str.find(')');
            //��ȡֵ
            auto sss = str.substr(index_num + 1, index_a - 1-index_num);
            e.value = sss;
            s[index].push_back(e);
        }
        else if (line == "PL")
        {
            e.label = '+';
            s[index].push_back(e);
        }
        else if (line == "MI")
        {
            e.label = '-';
            s[index].push_back(e);
        }
        else if (line == "MU")
        {
            e.label = '*';
            s[index].push_back(e);
        }
        else if (line == "DI")
        {
            e.label = '/';
            s[index].push_back(e);
        }
        else if (line == "IS")
        {
            e.label = '=';
            s[index].push_back(e);
        }
        else if (line == "SEMICOLON")
        {
            e.label = ';';
            s[index].push_back(e);
            index++;
        }
        else if (line == "ID")
        {
            e.label = 'h';
            //��ʶ����ֵ
            auto index_a = str.find(')');
            auto sss = str.substr(index_num + 1, index_a - 1 - index_num);
            e.value = sss;
            s[index].push_back(e);
        }
        else if (line == "L_P")
        {
            e.type = line;
            e.label = '(';
            s[index].push_back(e);
        }
        else if (line == "R_P")
        {
            e.type = line;
            e.label = ')';
            s[index].push_back(e);
        }
    }
    return s;
}
string return_s(vector<string> v)
{
    string s;
    for (auto c : v)
    {
        s += c;
    }
    return s;
}
//��ȡԤ��������չʾ
string get_Reserve_strings(vector<element> v)
{
    string s;
    for (auto c : v)
    {
        s += c.label;
    }
    s += '#';
    return s;
}
string generate_for(char c1,char c2,string op,string &value)
{
    string s;
    string s1 = string(1, c1);
    string s2 = string(1, c2);
    auto num1 = key_value[s1];
    auto num2 = key_value[s2];
    int a1, a2;
    if (s1 != "V")
    {
        ss << num1;
        ss >> a1;
        ss.clear();
    }
    ss << num2;
    ss >> a2;
    ss.clear();
    int num;
    //c1��c2���ݸ�����ֵ����
    if (op == "+")
    {
        if (a1 + a2 > 65536)
        {
            //���
            throw runtime_error("�������!");
            return s;
        }
        num = a1+a2;
    }
    else if (op == "-")
    {
        num = a1 - a2;
    }
    else if (op == "*")
    {
        num = a1 * a2;
    }
    else if (op == "/")
    {
        if (a2 == 0)
        {
            //������0����������
            throw runtime_error("��������Ϊ0!");
            return s;
        }
        num = a1 / a2;
    }
    else if (op == "=")
    {
        s = "(" + op + ", " + "," + num2 + ","+ num1+")";
        value = num2;
        return s;
    }
    else
    {
        return s;
    }
    s = "(" + op + "," + num1 + "," + num2 + ",";
    num1 = to_string(num);
    value = num1;
    s += num1;
    s += ")";
    return s;
}
void LR_anlayze(vector<string> s_status, vector<string> s_char, vector<element> v_e)
{
    //��¼����
    int step = 1;
    string s = get_Reserve_strings(v_e);
    
    //��¼��ǰ����ķ���λ��
    int index_element = 0;
    while (true)
    {
        //״̬ջ
        string c1 = s_status.back();
        ss << c1;
        int index_c1;
        ss >> index_c1;
        ss.clear();
        auto c2 = s[0];
        string action = m->m_next[index_c1][c2];
        //�����ֶ���,һ���Ǵ�R,һ���Ǵ�S,����һ��ֻ������
        int index_R = action.find('R');
        int index_S = action.find('S');
        if (action == "acc")
        {
            string tostatus = action.substr(index_R + 1);
            string s_statuss = return_s(s_status);
            string s_chars = return_s(s_char);
            std::cout << step << "\t" << left << setw(25)<< s_statuss << left << setw(15)<<s_chars << left << setw(30) << s << left << setw(15)
                << "acc" << endl;
            break;
        }
        else
        {
            if (index_R != string::npos)
            {
                //��Լ
                string tostatus = action.substr(index_R + 1);
                string s_statuss = return_s(s_status);
                string s_chars = return_s(s_char);
                ss << tostatus;
                int index_RR = 0;
                ss >> index_RR;
                ss.clear();
                string Pro = production[index_RR];
                char char_swap = Pro[0];
                string cc = "";
                cc.append(1, char_swap);
                Pro = Pro.substr(3);
                //�ж�����
                string s_key = s_chars.substr(s_chars.length() - Pro.size());
                for (int i = 0; i < Pro.size(); i++)
                {
                    s_char.pop_back();
                    s_status.pop_back();
                }
                auto ccc = cc;
                //�����ת����
                string s_strs = return_s(s_char);
                
                if (s_strs.find(cc) != string::npos)
                {
                    //�����ҵ�,������ͻ
                    cc = repeat_replace[index_element];
                    index_element++;
                }
                s_char.push_back(cc);
                auto s_statusss = return_s(s_status);
                auto s_charsss = return_s(s_char);
                tostatus = s_status.back();
                ss << tostatus;
                ss >> index_RR;
                ss.clear();
                action = m->m_next[index_RR][ccc[0]];
                ss << action;
                string sss;
                ss >> sss;
                ss.clear();
                //cc��Ҫ�滻�ɵ��ַ���,
                if (Pro.size() == 1)
                {
                    //����Ƿ��ս��
                    if (!key_value[Pro].empty())
                    {
                        key_value[cc] = key_value[Pro];
                    }
                    else
                    {
                        key_value[cc] = v_e[(v_e.size() - s.size())].value;
                    }
                    //�����Լ����
                    std::cout << step << "\t" << left << setw(25) << s_statuss << left << setw(15) << s_chars << left << setw(30) << s << left << setw(15)
                        << "R" + action << left << setw(15) << cc + ".value=" + key_value[cc] << endl;
                    step++;
                }
                else
                {
                    //������Ԫʽ
                    string operate = Pro.substr(1,1);
                    string data_new;
                    try 
                    {
                        string value = generate_for(s_key[0], s_key[2], operate, data_new);
                        //�����()��ֱ����
                        if (data_new.empty())
                        {
                            string ss = string(1, s_chars[s_chars.size() - 2]);
                            key_value[cc] = key_value[ss];
                            //�����Լ����
                            std::cout << step << "\t" << left << setw(25) << s_statuss << left << setw(15) << s_chars << left << setw(30) << s << left << setw(15)
                                << "R" + action << left << setw(15) << cc + ".value=" + key_value[cc] << endl;
                            step++;
                        }
                        else
                        {
                            //�����Լ����
                            std::cout << step << "\t" << left << setw(25) << s_statuss << left << setw(15) << s_chars << left << setw(30) << s << left << setw(15)
                                << "R" + action << left << setw(15) << "���ɲ���ʽ:" + data_new << left << setw(10) << value << endl;
                            //��ֵ�����µ��ս��
                            key_value[cc] = data_new;
                            step++;
                        }
                    }
                    catch (exception& e)
                    {
                        cerr << "���ִ���:" << e.what() << endl;
                        return;
                    }
                }
                //�����ת����
                std::cout << step << "\t" << left << setw(25)<<s_statusss << left << setw(15) << s_charsss << left << setw(30) << s << left << setw(15)
                    << "Goto(" + tostatus + "," + cc + ")=" + sss << endl;
                s_status.push_back(sss);
                step++;
            }
            else if (index_S != string::npos)
            {
                //��
                string tostatus = action.substr(index_S + 1);
                string s_statuss = return_s(s_status);
                string s_chars = return_s(s_char);
                std::cout << step << "\t" << left << setw(25)<<s_statuss << left << setw(15)<< s_chars << left << setw(30) << s << left << setw(15)
                    << action << endl;
                s_status.push_back(tostatus);
                string cc = "";
                cc.append(1, c2);
                s_char.push_back(cc);
                s = s.substr(1);
                step++;
            }
            else
            {
                cout << "error!" << endl;
                return;
            }
        }
    }
}
int main()
{
    //��ʼ�����
    ifstream csv_data("C:\\Users\\������\\Desktop\\��.csv", std::ios::in);
    string line;
    istringstream sin;         //�������ַ���line���뵽�ַ���istringstream��
    string word;
    //��ȡ��ͷԪ��
    vector<char> v;
    std::getline(csv_data, line);
    sin.clear();
    line = line.substr(3);
    sin.str(line);
    while (std::getline(sin, word, ','))
    {
        auto w = word[0];
        v.push_back(w);
    }
    int linenum = 0;
    while (std::getline(csv_data, line))
    {
        sin.clear();
        sin.str(line);
        int charnum = 0;
        //���ַ�����sin�е��ַ�����field�ַ����У��Զ���Ϊ�ָ���
        while (std::getline(sin, word, ','))
        {
            if (word != "")
            {
                m->m_next[linenum][v[charnum]] = word;
            }
            charnum++;
        }
        linenum++;
    }
    csv_data.close();
    //��ʼ��Ԥ����
    string src = "D:\\����ԭ��ʵ���������\\out_shiyan3.txt";
    auto str = init_keyword(src);
    vector<string> s_status;
    s_status.push_back("0");
    init_production(production);
    for (int i = 0; i < src.size(); i++)
    {
        if (str[i].empty())
        {
            break;
        }
        cout<<"---------------------------------------" << "��" << i + 1 << "��" << "----------------------------------------------------------------------------" << endl;
        vector<string> s_char;
        s_char.push_back("#");
        std::cout << "����" << "\t" << left<<setw(25)<< "״̬ջ" << left << setw(15)<< "����ջ" << left << setw(30) << "������" << left << setw(15)
            << "��������" << left << setw(15) <<"�������" << left << setw(10) <<"�м��������"<<endl;
        LR_anlayze(s_status, s_char, str[i]);
    }
    return 0;
}

