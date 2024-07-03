#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAXSIZE 100
string gather_end;
typedef struct
{
    vector<string> data;
    string m_F[MAXSIZE];
    string m_L[MAXSIZE];
    map<char, int> m_index;
    map<char, int> c_end;
    vector<char> m_front[MAXSIZE];
    vector<char> m_back[MAXSIZE];
    map<char,char> m_equal;
    //map<char, int> m_index;
}Matrix_char;
Matrix_char* m;
//�ж��Ƿ��Ƿ��ս����,�Ƿ���true
bool is_end(char c)
{
    //�жϸ������ַ��Ƿ��Ƿ��ս����
    if (c >= 65 && c <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//�и��
void split(const string str, const string splits, vector<string>& v)
{
    //���ַ���ĩβҲ����ָ����������ȡ���һ��
    string strs = str + splits;
    size_t pos = strs.find(splits);
    int step = splits.size();
    // ���Ҳ����������ַ��������������� npos
    while (pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        v.push_back(temp);
        //ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
        strs = strs.substr(pos + step, strs.size());
        pos = strs.find(splits);
    }
}
void F_need(char c_end, string& str)
{
    int index = m->m_index[c_end];
    vector<string> v;
    //index�Ƿ��ս����λ��
    string s = m->data[index];
    //�и��ַ���,����|�ָ�
    split(s, "|", v);
    for (auto c : v)
    {
        //����ÿһ������ʽ,Ѱ�����һ���ս��,���û����pass
        if (c.size() == 1 && is_end(c[0]))
        {
            char to_char = c[0];
            F_need(to_char, str);
        }
        else
        {
            for (auto vv : c)
            {
                if (!is_end(vv))
                {
                    //���ս����Ӧ��first���Ͼ���
                    str += vv;
                    break;
                }
            }
        }
    }
}
void L_need(char c_end, string& str)
{
    int index = m->m_index[c_end];
    vector<string> v;
    //index�Ƿ��ս����λ��
    string s = m->data[index];
    //�и��ַ���,����|�ָ�
    split(s, "|", v);
    for (auto c : v)
    {
        //����ÿһ������ʽ,Ѱ�����һ���ս��,���û����pass
        if (c.size() == 1 && is_end(c[0]))
        {
            char to_char = c[0];
            L_need(to_char, str);
        }
        else
        {
            for (int j = c.size() - 1; j >= 0; j--)
            {
                char vv = c[j];
                if (!is_end(vv))
                {
                    //���ս����Ӧ��first���Ͼ���
                    str += vv;
                    break;
                }
            }
        }
    }
}
void char_find(char c)
{
    int index = m->m_index[c];
    //index�Ƿ��ս����λ��
    auto v =  m->data;
    //�������еĲ���ʽ
    for (auto ss : v)
    {
        vector<string> vv;
        //�и��ַ���,����|�ָ�
        split(ss, "|", vv);
        for (auto cc : vv)
        {
            if (cc.find(c) != string::npos)
            {
                int ii = cc.find(c);
                if (ii - 1 >= 0)
                {
                    if (!is_end(cc[ii - 1]))
                    {
                        m->m_front[index].push_back(cc[ii-1]);
                    }
                }
                else if (ii + 1 < cc.size())
                {
                    if (!is_end(cc[ii + 1]))
                    {
                        m->m_back[index].push_back(cc[ii + 1]);
                    }
                }
                else if (ii + 1 < cc.size() && ii - 1 >= 0)
                {
                    if (!is_end(cc[ii - 1]) && !is_end(cc[ii + 1]))
                    {
                        m->m_equal[cc[ii - 1]] == cc[ii + 1];
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
}
void conduct_Matrix()
{
    m = new Matrix_char();
    string str;
    int index = 0;
    cout << "�������ķ�,��end����" << endl;
    //��Ϊ�涨��д��ĸ��Ϊ���ս��,����Ϊ�ս��
    while (true)
    {
        cin >> str;
        if (str == "end")
        {
            break;
        }
        gather_end += str[0];
        //m->m_index[str[0]] = index;
        m->m_index[str[0]] = index;
        str = str.substr(3);
        m->data.push_back(str);
        index++;
    }
    str = "";
    //����ÿһ�����ս����firstlst
    for (int i = 0; i < gather_end.size(); i++)
    {
        F_need(gather_end[i], str);
        m->m_F[i] = str;
        str = "";
    }
    //�����followlst��
    for (int i = 0; i < gather_end.size(); i++)
    {
        L_need(gather_end[i], str);
        m->m_L[i] = str;
        str = "";
    }
    index = 0;
    for (auto c : gather_end)
    {
        //Ѱ��ÿһ���ַ����ֵ�ǰ���ս��ַ����ս��ַ�
        char_find(gather_end[index]);
        index++;
    }
}