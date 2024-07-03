//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//#define MAXSIZE 100
//string gather_end;
//typedef struct
//{
//    vector<string> data;
//    string m_F[MAXSIZE];
//    string m_L[MAXSIZE];
//    map<char,int> m_index;
//    map<char, int> c_end;
//    //map<char, int> m_index;
//}Matrix_char;
//Matrix_char* m;
////判断是否是非终结符号,是返回true
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
////切割函数
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
//void F_need(char c_end,string& str)
//{
//    int index = m->m_index[c_end];
//    vector<string> v;
//    //index是非终结符的位置
//    string s = m->data[index];
//    //切割字符串,按照|分隔
//    split(s, "|", v);
//    for (auto c : v)
//    {
//        //对于每一个产生式,寻找其第一个终结符,如果没有则pass
//        if (c.size() == 1 && is_end(c[0]))
//        {
//            char to_char = c[0];
//            F_need(to_char,str);
//        }
//        else
//        {
//            for (auto vv : c)
//            {
//                if (!is_end(vv))
//                {
//                    //非终结符对应的first集合矩阵
//                    str += vv;
//                    break;
//                }
//            }
//        }
//    }
//}
//void L_need(char c_end, string& str)
//{
//    int index = m->m_index[c_end];
//    vector<string> v;
//    //index是非终结符的位置
//    string s = m->data[index];
//    //切割字符串,按照|分隔
//    split(s, "|", v);
//    for (auto c : v)
//    {
//        //对于每一个产生式,寻找其第一个终结符,如果没有则pass
//        if (c.size() == 1 && is_end(c[0]))
//        {
//            char to_char = c[0];
//            L_need(to_char, str);
//        }
//        else
//        {
//            for (int j = c.size() - 1; j >= 0; j--)
//            {
//                char vv = c[j];
//                if (!is_end(vv))
//                {
//                    //非终结符对应的first集合矩阵
//                    str += vv;
//                    break;
//                }
//            }
//        }
//    }
//}
//void conduct_Matrix()
//{
//    m = new Matrix_char();
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
//        //m->m_index[str[0]] = index;
//        m->m_index[str[0]] = index;
//        str = str.substr(3);
//        m->data.push_back(str);
//        index++;
//    }
//    str = "";
//    //构造每一个非终结符的firstlst
//    for (int i = 0; i < gather_end.size(); i++)
//    {
//        F_need(gather_end[i],str);
//        m->m_F[i] = str;
//        str = "";
//    }
//    index = 0;
//    for (auto c : m->m_F)
//    {
//        for (auto cc : c)
//        {
//            //对于每一个字符
//            if (m->c_end[cc] != NULL)
//            {
//                int index_c = m->c_end[cc];
//                m->m_index[index_c][cc] = '<';
//            }
//        }
//    }
//    //构造和followlst集
//    for (int i = 0; i < gather_end.size(); i++)
//    {
//        L_need(gather_end[i], str);
//        m->m_L[i] = str;
//        str = "";
//    }
//}
//int main()
//{
//    conduct_Matrix();
//}