//#include<iostream>
//#include<string>
//#include<map>
//#include<fstream>
//#include<vector>  
//#include<stack>
//#include <algorithm>
//#include<set>
//#define MAXSIZE 20
//using namespace std;
////���ݸ�����Key(���ս��)������Ӧ��first����
//typedef struct
//{
//    vector<string> m_first[MAXSIZE];
//    map<char, int> K_index;
//    string m_follow[MAXSIZE];
//    //����δ������ս��
//    vector<char> v_need[MAXSIZE];
//    vector<char> v_needf[MAXSIZE];
//    map<string, int> m;
//}analyzer;
//analyzer* a;
//string gather_end;
//vector<char> v_nend;
//bool is_end(char c)
//{
//    //�жϸ������ַ��Ƿ��Ƿ��ս����
//    if (c >= 65 && c <= 90)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//// ʹ���ַ����ָ�
//void split(const string str, const string splits, vector<string>& v)
//{
//    //���ַ���ĩβҲ����ָ����������ȡ���һ��
//    string strs = str + splits;
//    size_t pos = strs.find(splits);
//    int step = splits.size();
//    // ���Ҳ����������ַ��������������� npos
//    while (pos != strs.npos)
//    {
//        string temp = strs.substr(0, pos);
//        v.push_back(temp);
//        //ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
//        strs = strs.substr(pos + step, strs.size());
//        pos = strs.find(splits);
//    }
//}
////���ط��ս����first����,���ַ�������ʽ
//bool v_first(vector<string> v,string &s)
//{
//    bool is_have = false;
//    for (auto c : v)
//    {
//        for (int i = 0;i<c.size();i++)
//        {
//            auto k = c[i];
//            if (k != -90)
//            {
//                s += k;
//            }
//            else
//            {
//                is_have = true;
//                i++;
//            }
//        }
//    }
//    return is_have;
//}
//map<int, vector<string>> v_need(vector<string> v,char k)
//{
//    map<int, vector<string>> s;
//    int count = -1;
//    for (auto c : v)
//    {
//        count++;
//        auto index = c.find(k);
//        if (index == string::npos)
//        {
//            continue;
//        }
//        vector<string> vv;
//        //�и��ַ���,����|�ָ�
//        split(c, "|", vv);
//        for (auto kk : vv)
//        {
//            auto index = kk.find(k);
//            if (index != string::npos)
//            {
//                s[count].push_back(kk);
//            }
//        }
//    }
//    return s;
//}
//void unique_s(string &s)
//{
//    set<char> ss;
//    //��string������ַ�����װ��set���ϼ��������
//    for (int i = 0; i < s.length(); i++) {
//        ss.insert(s[i]);
//    }
//    string str_res = "";
//    for (auto it = ss.begin(); it != ss.end(); it++) {
//        //'\0'
//        if (*it == '\0') break;
//        str_res.push_back(*it);
//    }
//    s = str_res;
//}
////�ж�ÿһ�����ս���ŵ�first�����Ƿ�Ϊ��
//bool if_NULL()
//{
//    for (int i = 0;i<v_nend.size();i++)
//    {
//        auto c = a->m_first[i];
//        if (c.empty())
//        {
//            //���ڿյ�
//            return true;
//        }
//    }
//    for (int i = 0; i < v_nend.size(); i++)
//    {
//        auto c = a->v_need[i];
//        if (!c.empty())
//        {
//            return true;
//        }
//    }
//    return false;
//}
//bool if_NULL_f()
//{
//    for (int i = 0; i < v_nend.size(); i++)
//    {
//        auto c = a->m_follow[i];
//        if (c.empty())
//        {
//            //���ڿյ�
//            return true;
//        }
//    }
//    for (int i = 0; i < v_nend.size(); i++)
//    {
//        auto c = a->v_needf[i];
//        if (!c.empty())
//        {
//            return true;
//        }
//    }
//    return false;
//}
////�����ķ�,����follow����first��
//void conduct_Matrix()
//{
//    vector<string> v_production;
//    a = new analyzer();
//    string str;
//    int index = 0;
//    cout << "�������ķ�,��end����" << endl;
//    //��Ϊ�涨��д��ĸ��Ϊ���ս��,����Ϊ�ս��
//    while (true)
//    {
//        cin >> str;
//        if (str == "end")
//        {
//            break;
//        }
//        gather_end += str[0];
//        a->K_index[str[0]] = index++;
//        v_nend.push_back(str[0]);
//        v_production.push_back(str.substr(3));
//    }
//    //��ɨ��һ��,��ȡ�÷��ս��������Ҫ�����з��ս���ŵ�first��,�����first������,�����
//    //����ѭ��;�����ս����,����
//    for (int i = 0; i < v_nend.size(); i++)
//    {
//        int nn = 0;
//        char K = v_nend[i];
//        index = a->K_index[K];
//        string production = v_production[i];
//        vector<string> v;
//        //�и��ַ���,����|�ָ�
//        split(v_production[i], "|",v);
//        //����ÿһ������ʽ
//        for (auto c : v)
//        {
//            //����ÿһ������ʽ��ÿһ���ַ�
//            for (auto k : c)
//            {
//                if (!is_end(k))
//                {
//                    if (k == -90)
//                    {
//                        string s = "\u03B5";
//                        a->m_first[index].push_back(s);
//                        nn++;
//                        break;
//                    }
//                    else
//                    {
//                        string s = "";
//                        s.append(1, k);
//                        a->m_first[index].push_back(s);
//                        nn++;
//                        break;
//                    }
//                }
//                else
//                {
//                    //���ҷ��ս������Ҫ��first����
//                    a->m_first[index].push_back("");
//                    a->v_need[index].push_back(k);
//                    string ss;
//                    ss.push_back(K);
//                    ss.push_back(k);
//                    a->m[ss] == nn;
//                    break;
//                }
//            }
//        }
//        
//    }
//    while (true)
//    {
//        if (!if_NULL())
//        {
//            break;
//        }
//        for (int i = 0; i < v_nend.size(); i++)
//        {
//            int index = i;
//            char c_end = v_nend[i];
//            if (a->v_need[index].empty())
//            {
//                //��ȱ�ٷ��ս��
//                continue;
//            }
//            else
//            {
//                for (auto c : a->v_need[index])
//                {
//                    int index_c = a->K_index[c];
//                    if (!a->v_need[index_c].empty())
//                    {
//                        continue;
//                    }
//                    else
//                    {
//                        string s;
//                        bool panduan = v_first(a->m_first[index_c], s);
//                        if (panduan)
//                        {
//                            //���пմ�,���ݲ���ʽ������һ�����ŵ�first��
//                            string production = v_production[i];
//                            vector<string> v;
//                            //�и��ַ���,����|�ָ�
//                            split(v_production[i], "|", v);
//                            for (auto z : v)
//                            {
//                                if (z.find(c) != string::npos)
//                                {
//                                    int zz = z.find(c);
//                                    if (zz + 1 < z.size())
//                                    {
//                                        a->v_need[index].push_back(z[zz + 1]);
//                                    }
//                                }
//                            }
//                        }
//                        //��first�����뵽��first����
//                        string sss = "";
//                        sss.push_back(c_end);
//                        sss.push_back(c);
//                        auto index11 = a->m[sss];
//                        a->m_first[index][index11] = s;
//                        //��Ԫ���Ƴ�
//                        auto ii = find(a->v_need[index].begin(), a->v_need[index].end(), c);
//                        a->v_need[index].erase(ii,ii+1);
//                    }
//                }
//            }
//        }
//    }
//    //����follow��
//    //��ɨ��һ��,��ȡ���е�fisst���Ϻ�#
//    for (int i = 0; i <= v_nend.size() - 1; i++)
//    {
//        int index = i;
//        string str = "";
//        if (i == 0)
//        {
//            //��ʼ��
//            str += "#";
//        }
//        char c = v_nend[i];
//        auto s = v_need(v_production, c);
//        for (map<int, vector<string>>::iterator it = s.begin(); it != s.end(); it++)
//        {
//            //��һ������,�ڶ���Ϊ�����ַ���
//            if (it->first == a->K_index[c])
//            {
//                continue;
//            }
//            else
//            {
//                for (auto kk : it->second)
//                {
//                    int location = kk.find(c);
//                    if (location == kk.size() - 1)
//                    {
//                        if (a->v_needf[it->first].empty() && !a->m_follow[it->first].empty())
//                        {
//                            //��follow(B)��һ�з��ż��뵽follow(A)
//                            str += a->m_follow[it->first];
//                            //�����follow������ɾ��
//                            auto ii = find(a->v_needf[it->first].begin(), a->v_needf[it->first].end(), v_nend[it->first]);
//                            if (ii != a->v_needf[it->first].end())
//                            {
//                                a->v_needf[it->first].erase(ii, ii + 1);
//                            }
//                           
//                        }
//                        else
//                        {
//                            //���뵽��Ҫfollow������
//                            a->v_needf[index].push_back(v_nend[it->first]);
//                        }
//                    }
//                    else
//                    {
//                        //it->first���±�,it->second�Ǻ���c�Ĳ���ʽ
//                        if (!is_end(kk[location + 1]) && kk[location + 1] != '|')
//                        {
//                            //�ս��
//                            str += kk[location + 1];
//                        }
//                        else
//                        {
//                            //���ս��,�ж���һ��λ��
//                            char b = kk[location + 1];
//                            string s;
//                            bool panduan = v_first(a->m_first[a->K_index[b]], s);
//                            str += s;
//                            if (panduan)
//                            {
//                                //��b�е�follow���ϼ��뵽A��,���B��follow���ϲ����ڻ�δ����,����ʱ������
//                                if (a->v_needf[it->first].empty() && !a->m_follow[it->first].empty())
//                                {
//                                    //��follow(B)��һ�з��ż��뵽follow(A)
//                                    str += a->m_follow[it->first];
//                                    //�����follow������ɾ��
//                                    auto ii = find(a->v_needf[it->first].begin(), a->v_needf[it->first].end(), v_nend[it->first]);
//                                    if (ii != a->v_needf[it->first].end())
//                                    {
//                                        a->v_needf[it->first].erase(ii, ii + 1);
//                                    }
//                                    
//                                }
//                                else
//                                {
//                                    //���뵽��Ҫfollow������
//                                    a->v_needf[index].push_back(v_nend[it->first]);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        unique_s(str);
//        a->m_follow[a->K_index[c]] = str;
//    }
//    while (true)
//    {
//        if (!if_NULL_f())
//        {
//            break;
//        }
//        for (int i = 0; i < v_nend.size(); i++)
//        {
//            int index = i;
//            char c_end = v_nend[i];
//            if (a->v_needf[index].empty())
//            {
//                //��ȱ��follow����
//                continue;
//            }
//            else
//            {
//                for (auto c : a->v_needf[index])
//                {
//                    //����ÿһ�����ս����
//                    int index_c = a->K_index[c];
//                    //�鿴followC �Ƿ�ok��
//                    if (a->m_follow[index_c].empty() || !a->v_needf[index_c].empty())
//                    {
//                        //δ��ʼ������,���Լ���ѭ��
//                        continue;
//                    }
//                    else
//                    {
//                        a->m_follow[i] += a->m_follow[index_c];
//                        //��
//                        auto ii = find(a->v_needf[i].begin(), a->v_needf[i].end(),c);
//                        a->v_needf[i].erase(ii, ii + 1);
//                    }
//                }
//            }
//            unique_s(a->m_follow[index]);
//        }
//    }
//}
//int main()
//{
//    conduct_Matrix();
//    cout << "first��" <<"\t\t"<< "follow��" << endl;
//    int index;
//    for (auto c : gather_end)
//    {
//        cout << c << ":";
//        for (auto k : a->m_first[a->K_index[c]])
//        {
//            cout << k << " ";
//        }
//        cout << "\t\t";
//        cout << a->m_follow[a->K_index[c]] << endl;
//        cout << endl;
//    }
//    /*cout << "follow��:" << endl;
//    for (auto c : gather_end)
//    {
//        cout << c << ":";
//    }*/
//}