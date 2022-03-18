#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    int n;
    char start;
    cin >> n >> start;
    vector< vector< vector<int> > > v(30, vector< vector<int> >(30, vector<int>()));
    for (int i = 0; i < n; i++) {
        char from, b, to;
        string line1, line2, line3;
        cin >> line1 >> line2 >> line3;
        from = line1[0];
        b = line3[0];
        if (line3.size() == 2) {
            to = line3[1];
            v[from - 'A' + 1][b - 'a'].push_back(to - 'A' + 1);
        } else {
            v[from - 'A' + 1][b - 'a'].push_back(0);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        vector< vector<bool> > can(str.size() + 1, vector<bool>(30, 0));
        can[0][start - 'A' + 1] = 1;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < 27; j++) {
                if (can[i][j]) {
                    for (int h = 0; h < v[j][str[i] - 'a'].size(); h++) {
                        can[i + 1][v[j][str[i] - 'a'][h]] = 1;
                    }
                }
            }
        }
        if (can[str.size()][0]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
