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
////根据给定的Key(非终结符)求出其对应的first集合
//typedef struct
//{
//    vector<string> m_first[MAXSIZE];
//    map<char, int> K_index;
//    string m_follow[MAXSIZE];
//    //存在未处理的终结符
//    vector<char> v_need[MAXSIZE];
//    vector<char> v_needf[MAXSIZE];
//    map<string, int> m;
//}analyzer;
//analyzer* a;
//string gather_end;
//vector<char> v_nend;
//bool is_end(char c)
//{
//    //判断给定的字符是否是非终结符号
//    if (c >= 65 && c <= 90)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//// 使用字符串分割
//void split(const string str, const string splits, vector<string>& v)
//{
//    //在字符串末尾也加入分隔符，方便截取最后一段
//    string strs = str + splits;
//    size_t pos = strs.find(splits);
//    int step = splits.size();
//    // 若找不到内容则字符串搜索函数返回 npos
//    while (pos != strs.npos)
//    {
//        string temp = strs.substr(0, pos);
//        v.push_back(temp);
//        //去掉已分割的字符串,在剩下的字符串中进行分割
//        strs = strs.substr(pos + step, strs.size());
//        pos = strs.find(splits);
//    }
//}
////返回非终结符的first集合,以字符串的形式
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
//        //切割字符串,按照|分隔
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
//    //将string里面的字符依次装入set集合即可完完成
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
////判断每一个非终结符号的first集合是否为空
//bool if_NULL()
//{
//    for (int i = 0;i<v_nend.size();i++)
//    {
//        auto c = a->m_first[i];
//        if (c.empty())
//        {
//            //存在空的
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
//            //存在空的
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
////输入文法,构造follow集和first集
//void conduct_Matrix()
//{
//    vector<string> v_production;
//    a = new analyzer();
//    string str;
//    int index = 0;
//    cout << "请输入文法,以end结束" << endl;
//    //人为规定大写字母均为非终结符,其余为终结符
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
//    //先扫描一遍,获取该非终结符号所需要的所有非终结符号的first集,如果该first集存在,则加入
//    //否则循环;对于终结符号,加入
//    for (int i = 0; i < v_nend.size(); i++)
//    {
//        int nn = 0;
//        char K = v_nend[i];
//        index = a->K_index[K];
//        string production = v_production[i];
//        vector<string> v;
//        //切割字符串,按照|分隔
//        split(v_production[i], "|",v);
//        //遍历每一个产生式
//        for (auto c : v)
//        {
//            //遍历每一个产生式的每一个字符
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
//                    //查找非终结符号需要的first集合
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
//                //不缺少非终结符
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
//                            //含有空串,根据产生式加入下一个符号的first集
//                            string production = v_production[i];
//                            vector<string> v;
//                            //切割字符串,按照|分隔
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
//                        //将first集加入到其first集中
//                        string sss = "";
//                        sss.push_back(c_end);
//                        sss.push_back(c);
//                        auto index11 = a->m[sss];
//                        a->m_first[index][index11] = s;
//                        //将元素移除
//                        auto ii = find(a->v_need[index].begin(), a->v_need[index].end(), c);
//                        a->v_need[index].erase(ii,ii+1);
//                    }
//                }
//            }
//        }
//    }
//    //构造follow集
//    //先扫描一遍,获取所有的fisst集合和#
//    for (int i = 0; i <= v_nend.size() - 1; i++)
//    {
//        int index = i;
//        string str = "";
//        if (i == 0)
//        {
//            //开始符
//            str += "#";
//        }
//        char c = v_nend[i];
//        auto s = v_need(v_production, c);
//        for (map<int, vector<string>>::iterator it = s.begin(); it != s.end(); it++)
//        {
//            //第一个索引,第二个为所有字符串
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
//                            //将follow(B)的一切符号加入到follow(A)
//                            str += a->m_follow[it->first];
//                            //将其从follow集合中删除
//                            auto ii = find(a->v_needf[it->first].begin(), a->v_needf[it->first].end(), v_nend[it->first]);
//                            if (ii != a->v_needf[it->first].end())
//                            {
//                                a->v_needf[it->first].erase(ii, ii + 1);
//                            }
//                           
//                        }
//                        else
//                        {
//                            //加入到需要follow集合中
//                            a->v_needf[index].push_back(v_nend[it->first]);
//                        }
//                    }
//                    else
//                    {
//                        //it->first是下标,it->second是含有c的产生式
//                        if (!is_end(kk[location + 1]) && kk[location + 1] != '|')
//                        {
//                            //终结符
//                            str += kk[location + 1];
//                        }
//                        else
//                        {
//                            //非终结符,判断下一个位置
//                            char b = kk[location + 1];
//                            string s;
//                            bool panduan = v_first(a->m_first[a->K_index[b]], s);
//                            str += s;
//                            if (panduan)
//                            {
//                                //将b中的follow集合加入到A中,如果B的follow集合不存在或未结束,则暂时不加入
//                                if (a->v_needf[it->first].empty() && !a->m_follow[it->first].empty())
//                                {
//                                    //将follow(B)的一切符号加入到follow(A)
//                                    str += a->m_follow[it->first];
//                                    //将其从follow集合中删除
//                                    auto ii = find(a->v_needf[it->first].begin(), a->v_needf[it->first].end(), v_nend[it->first]);
//                                    if (ii != a->v_needf[it->first].end())
//                                    {
//                                        a->v_needf[it->first].erase(ii, ii + 1);
//                                    }
//                                    
//                                }
//                                else
//                                {
//                                    //加入到需要follow集合中
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
//                //不缺少follow集合
//                continue;
//            }
//            else
//            {
//                for (auto c : a->v_needf[index])
//                {
//                    //遍历每一个非终结符号
//                    int index_c = a->K_index[c];
//                    //查看followC 是否ok了
//                    if (a->m_follow[index_c].empty() || !a->v_needf[index_c].empty())
//                    {
//                        //未初始化结束,所以继续循环
//                        continue;
//                    }
//                    else
//                    {
//                        a->m_follow[i] += a->m_follow[index_c];
//                        //出
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
//    cout << "first集" <<"\t\t"<< "follow集" << endl;
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
//    /*cout << "follow集:" << endl;
//    for (auto c : gather_end)
//    {
//        cout << c << ":";
//    }*/
//}