#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int> > & listWays, vector<bool> & poss) {
    poss[v] = 1;
    for (int i = 0; i < listWays[v].size(); i++) {
        if (!poss[listWays[v][i]]) {
            dfs(listWays[v][i], listWays, poss);
        }
    }
}

int main()
{
    freopen("useless.in", "r", stdin);
    freopen("useless.out", "w", stdout);
    int n;
    char start;
    cin >> n >> start;
    vector<vector<int> > productions(n, vector<int>());
    vector<bool> gen(27, 0);
    set<int> nterm;
    vector<int> cnt(n, 0);
    vector<vector<int> > rightRules(27, vector<int>());
    queue<int> q;
    nterm.insert(start - 'A' + 1);
    string line;
    getline(cin, line);
    set<int> was;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        char from = line[0];
        productions[i].push_back(from - 'A' + 1);
        nterm.insert(from - 'A' + 1);
        int _cnt = 0;
        for (int y = 5; y < line.size(); y++) {
            if ('A' <= line[y] && line[y] <= 'Z') {
                productions[i].push_back(line[y] - 'A' + 1);
                nterm.insert(line[y] - 'A' + 1);
                _cnt++;
                rightRules[line[y] - 'A' + 1].push_back(i);
            }
        }
        cnt[i] = _cnt;
        if (cnt[i] == 0) {
            gen[from - 'A' + 1] = 1;
            if (was.find(from - 'A' + 1) == was.end()) {
                q.push(from - 'A' + 1);
                was.insert(from - 'A' + 1);
            }
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < rightRules[curr].size(); i++) {
            cnt[rightRules[curr][i]]--;
            if (cnt[rightRules[curr][i]] == 0) {
                gen[productions[rightRules[curr][i]][0]] = 1;
                if (was.find(productions[rightRules[curr][i]][0]) == was.end()) {
                    q.push(productions[rightRules[curr][i]][0]);
                    was.insert(productions[rightRules[curr][i]][0]);
                }
            }
        }
    }
    vector<vector<int> > listWays (27, vector<int>());
    for (int i = 0; i < n; i++) {
        bool accept = 1;
        for (int j = 0; j < productions[i].size(); j++) {
            if (!gen[productions[i][j]]) {
                accept = 0;
                break;
            }
        }
        if (accept) {
            for (int j = 1; j < productions[i].size(); j++) {
                listWays[productions[i][0]].push_back(productions[i][j]);
            }
        }
    }
    vector<bool> poss(27, 0);
    if (gen[start - 'A' + 1]) {
        dfs(start - 'A' + 1, listWays, poss);
    }
    for (set<int>::iterator i = nterm.begin(); i != nterm.end(); ++i) {
        if (!(gen[*i] && poss[*i])) {
            cout << char(*i + 'A' - 1) << ' ';
        }
    }
    return 0;
}
