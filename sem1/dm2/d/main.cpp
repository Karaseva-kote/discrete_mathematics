#include <bits/stdc++.h>

using namespace std;

vector <pair<string, int> > dic;

int main()
{
    //freopen("lzw.in", "r", stdin);
    //freopen("lzw.out", "w", stdout);
    for (int i = 0; i < 26; i++){
        string n = "";
        n += char(i + 'a');
        dic.push_back({n, i});
    }
    string s, t = "";
    cin >> s;
    t += s[0];
    for (int i = 1; i < s.size(); i++){
        string x = t + s[i];
        int code_t;
        bool have = 0;
        for (int j = 0; j < dic.size(); j++){
            if (dic[j].first == t)
                code_t = dic[j].second;
            if (dic[j].first == x){
                t = x;
                have = 1;
                break;
            }
        }
        if (!have){
            cout << code_t << ' ';
            dic.push_back({x, dic.size()});
            t = "";
            t += s[i];
        }
    }
    for (int i = 0; i < dic.size(); i++){
        if (dic[i].first == t){
            cout << dic[i].second << ' ';
            break;
        }
    }
    return 0;
}
