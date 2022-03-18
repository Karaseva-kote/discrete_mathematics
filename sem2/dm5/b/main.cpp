#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    string str;
    cin >> str;
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> term(n, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = 1;
    }
    vector< vector< vector<int> > > v(n, vector<vector <int> >(30, vector<int>()));
    for (int i = 0; i < m; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v[from - 1][c - 'a'].push_back(to - 1);
    }
    vector< vector<bool> > can(str.size() + 1, vector<bool>(n, 0));
    can[0][0] = 1;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (can[i][j]) {
                for (int h = 0; h < v[j][str[i] - 'a'].size(); h++) {
                    can[i + 1][v[j][str[i] - 'a'][h]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (can[str.size()][i] && term[i]) {
            cout << "Accepts";
            return 0;
        }
    }
    cout << "Rejects";
    return 0;
}
