#include <bits/stdc++.h>

using namespace std;

vector <string> v;

int main()
{
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        string new_s = "";
        for (int j = i; j < i + s.size(); j++){
            new_s += s[j % s.size()];
        }
        v.push_back(new_s);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < s.size(); i++){
        cout << v[i][s.size() - 1];
    }
    return 0;
}
