#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    string str;
    cin >> str;
    int n, m, k;
    cin >> n >> m >> k;
    set<int> allow;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        allow.insert(x - 1);
    }
    vector<map <char, int> > v(n, map<char, int>());
    for (int i = 0; i < m; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v[from - 1].insert(pair<char, int>(c, to - 1));
    }
    int condition = 0;
    for (int i = 0; i < str.size(); i++) {
        if (v[condition].find(str[i]) != v[condition].end()) {
            condition = v[condition].at(str[i]);
        } else {
            cout << "Rejects";
            return 0;
        }
    }
    if (allow.find(condition) != allow.end()) {
        cout << "Accepts";
    } else {
        cout << "Rejects";
    }
    return 0;
}
