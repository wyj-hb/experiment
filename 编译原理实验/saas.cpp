//#include<iostream>
//#include<math.h>
//#include <iostream>
//#include <istream>
//#include <streambuf>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//#include <stdlib.h>
//#include<map>
//#include<sstream>
//#include<stack>
//#define MAXSIZE 1000
//using namespace std;
//typedef struct
//{
//    //char�ҵ���Ӧindex���ַ���
//    map<char, string> m_next[MAXSIZE];
//}Matrix;
//typedef struct
//{
//    //������޷������Ļ�����ֵ��
//    int value;
//   // ��Ӧ������,��������ִ����Ӧ����
//    string type;
//
//}element;
//vector<string> production;
//stringstream ss;
//void init_production(vector<string>& v)
//{
//    v.push_back("S'->S");
//    v.push_back("S->wBdS");
//    v.push_back("S->iBeS");
//    v.push_back("S->iB");
//    v.push_back("S->H");
//    v.push_back("B->b");
//    v.push_back("B->G");
//    v.push_back("G->V>V");
//    v.push_back("G->V<V");
//    v.push_back("H->V=E;");
//    v.push_back("E->T");
//    v.push_back("E->E+T");
//    v.push_back("E->E-T");
//    v.push_back("T->F");
//    v.push_back("T->T*F");
//    v.push_back("F->z");
//    v.push_back("F->(E)");
//    v.push_back("V->h");
//    v.push_back("T->T/F");
//}
//Matrix* m = new Matrix();
//vector<string> init_keyword(string src)
//{
//    ifstream file(src);
//    string line;
//    vector<string> s(10);
//    int index = 0;
//    while (getline(file, line))
//    {
//        auto index_num = line.find(',');
//        line = line.substr(1, index_num - 1);
//        if (line == "INT" || line == "UCON" || line == "SCIENCE_NUM")
//        {
//            s[index] += "z";
//        }
//        else if (line == "PL")
//        {
//            s[index] += "+";
//        }
//        else if (line == "MI")
//        {
//            s[index] += "-";
//        }
//        else if (line == "MU")
//        {
//            s[index] += "*";
//        }
//        else if (line == "DI")
//        {
//            s[index] += "/";
//        }
//        else if (line == "IS")
//        {
//            s[index] += "=";
//        }
//        else if (line == "SEMICOLON")
//        {
//            s[index] += ";";
//            s[index] += "#";
//            index++;
//        }
//        else if (line == "ID")
//        {
//            s[index] += "h";
//        }
//        else if (line == "L_P")
//        {
//            s[index] += "(";
//        }
//        else if (line == "R_P")
//        {
//            s[index] += ")";
//        }
//        else if (line == "GT")
//        {
//            s[index] += '>';
//        }
//        else if (line == "LT")
//        {
//            s[index] += '<';
//        }
//        else if (line == "IF")
//        {
//            s[index] += 'i';
//        }
//        else if (line == "THEN")
//        {
//            s[index] += 'e';
//        }
//        else if (line == "WHILE")
//        {
//            s[index] += 'w';
//        }
//        else if (line == "DO")
//        {
//            s[index] += 'd';
//        }
//    }
//    return s;
//}
//string  return_s(vector<string> v)
//{
//    string s;
//    for (auto c : v)
//    {
//        s += c;
//    }
//    return s;
//}
//void LR_anlayze(vector<string> s_status, vector<string> s_char, string s_str)
//{
//    int step = 1;
//
//    while (true)
//    {
//        string c1 = s_status.back();
//        ss << c1;
//        int index_c1;
//        ss >> index_c1;
//        ss.clear();
//        auto c2 = s_str[0];
//        string action = m->m_next[index_c1][c2];
//        //�����ֶ���,һ���Ǵ�R,һ���Ǵ�S,����һ��ֻ������
//        int index_R = action.find('R');
//        int index_S = action.find('S');
//        if (action == "acc")
//        {
//            string tostatus = action.substr(index_R + 1);
//            string s_statuss = return_s(s_status);
//            string s_chars = return_s(s_char);
//            std::cout << step << "\t\t" << s_statuss << "\t\t" << s_chars << "\t\t" << s_str << "\t\t" << "acc" << endl;
//            break;
//        }
//        else
//        {
//            if (index_R != string::npos)
//            {
//                //��Լ
//                string tostatus = action.substr(index_R + 1);
//                string s_statuss = return_s(s_status);
//                string s_chars = return_s(s_char);
//                std::cout << step << "\t\t" << s_statuss << "\t\t" << s_chars << "\t\t" << s_str << "\t\t" << action << endl;
//                ss << tostatus;
//                int index_RR = 0;
//                ss >> index_RR;
//                ss.clear();
//                string Pro = production[index_RR];
//                char char_swap = Pro[0];
//                string cc = "";
//                cc.append(1, char_swap);
//                Pro = Pro.substr(3);
//                for (int i = 0; i < Pro.size(); i++)
//                {
//                    s_char.pop_back();
//                    s_status.pop_back();
//                }
//                s_char.push_back(cc);
//                step++;
//                //�����ת����
//                s_statuss = return_s(s_status);
//                s_chars = return_s(s_char);
//                tostatus = s_status.back();
//                ss << tostatus;
//                ss >> index_RR;
//                ss.clear();
//                action = m->m_next[index_RR][cc[0]];
//                ss << action;
//                string sss;
//                ss >> sss;
//                ss.clear();
//                std::cout << step << "\t\t" << s_statuss << "\t\t" << s_chars << "\t\t" << s_str << "\t\t" << "Goto(" << index_RR << "," + cc + ")=" + sss << endl;
//                s_status.push_back(sss);
//                step++;
//            }
//            else if (index_S != string::npos)
//            {
//                //��
//                string tostatus = action.substr(index_S + 1);
//                string s_statuss = return_s(s_status);
//                string s_chars = return_s(s_char);
//                std::cout << step << "\t\t" << s_statuss << "\t\t" << s_chars << "\t\t" << s_str << "\t\t" << action << endl;
//                s_status.push_back(tostatus);
//                string cc = "";
//                cc.append(1, c2);
//                s_char.push_back(cc);
//                s_str = s_str.substr(1);
//                step++;
//            }
//            else
//            {
//                cout << "error!" << endl;
//                return;
//            }
//        }
//    }
//}
//int main()
//{
//    //��ʼ�����
//    ifstream csv_data("C:\\Users\\������\\Desktop\\��.csv", std::ios::in);
//    string line;
//    istringstream sin;         //�������ַ���line���뵽�ַ���istringstream��
//    string word;
//   // ��ȡ��ͷԪ��
//    vector<char> v;
//    std::getline(csv_data, line);
//    sin.clear();
//    line = line.substr(3);
//    sin.str(line);
//    while (std::getline(sin, word, ','))
//    {
//        auto w = word[0];
//        v.push_back(w);
//    }
//    int linenum = 0;
//    while (std::getline(csv_data, line))
//    {
//        sin.clear();
//        sin.str(line);
//        int charnum = 0;
//        //���ַ�����sin�е��ַ�����field�ַ����У��Զ���Ϊ�ָ���
//        while (std::getline(sin, word, ','))
//        {
//            if (word != "")
//            {
//                m->m_next[linenum][v[charnum]] = word;
//            }
//            charnum++;
//        }
//        linenum++;
//    }
//    csv_data.close();
//    //��ʼ��Ԥ����
//    string src = "D:\\����ԭ��ʵ���������\\out_shiyan2_test_data.txt";
//    auto str = init_keyword(src);
//    vector<string> s_status;
//    s_status.push_back("0");
//    init_production(production);
//    for (int i = 0; i < src.size(); i++)
//    {
//        if (str[i].empty())
//        {
//            break;
//        }
//        cout << "---------------------------------------" << "��" << i + 1 << "��" << "---------------------------------------------" << endl;
//        vector<string> s_char;
//        s_char.push_back("#");
//        std::cout << "����" << "\t\t" << "״̬ջ" << "\t\t" << "����ջ" << "\t\t" << "������" << "\t\t" << "��������" << endl;
//        LR_anlayze(s_status, s_char, str[i]);
//    }
//    return 0;
//}
//
