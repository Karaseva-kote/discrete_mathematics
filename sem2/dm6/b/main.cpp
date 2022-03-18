#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
   // freopen("input.txt", "r", stdin);
    int n;
    char start;
    cin >> n >> start;
    set<char> ans;
    vector<vector<char> > productions;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        char from = line[0];
        if (line.size() == 4) {
            ans.insert(from);
            continue;
        }
        bool flag = 0;
        for (int k = 5; k < line.size(); k++) {
            if ('a' <= line[k] && line[k] <= 'z') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        vector<char> v;
        v.push_back(from);
        for (int y = 5; y < line.size(); y++) {
            v.push_back(line[y]);
        }
        productions.push_back(v);
    }
    int curC, newC;
    do {
        curC = ans.size();
        for (int i = 0; i < productions.size(); i++) {
            bool accept = 1;
            for (int j = 1; j < productions[i].size(); j++) {
                if (ans.find(productions[i][j]) == ans.end()) {
                    accept = 0;
                    break;
                }
            }
            if (accept) {
                ans.insert(productions[i][0]);
            }
        }
        newC = ans.size();
    } while(curC != newC);
    for (set<char>::iterator i = ans.begin(); i != ans.end(); ++i) {
        cout << *i << " ";
    }
    return 0;
}
