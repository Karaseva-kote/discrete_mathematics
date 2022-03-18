#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;
map<int, int> v[N];
vector<int> rev[N];
bool term[N], rich[N];
int color[N];
int n, m, k, maxdepth = 0;

bool dfs(int curr, int depth) {
    color[curr] = 1;
    maxdepth = max(maxdepth, depth);
    for (map <int, int> :: iterator now = v[curr].begin(); now != v[curr].end(); now++) {
        if (color[now->first] == 1) {
            return 0;
        }
        if (!dfs(now->first, depth + 1)){
            return 0;
        }
    }
    color[curr] = 2;
    return 1;
}

void t(int u) {
    rich[u] = 1;
    for (int i = 0; i < rev[u].size(); i++) {
        if (!rich[rev[u][i]]) {
            t(rev[u][i]);
        }
    }
}

int main()
{
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        rev[to - 1].push_back(from - 1);
        int cnt = 1;
        if (v[from - 1].find(to - 1) != v[from - 1].end()) {
            cnt = v[from - 1].at(to - 1) + 1;
            v[from - 1].erase(to - 1);
        }
        v[from - 1].insert(pair<int, int>(to - 1, cnt));
    }
    for (int i = 0; i < n; i++) {
        if (term[i]) {
            t(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!rich[i]) {
            v[i].clear();
        }
    }
    if (!dfs(0, 0)) {
        cout << -1;
        return 0;
    }
    vector< vector<long long> > dp(n, vector<long long>(maxdepth + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < maxdepth; i++) {
        for (int j = 0; j < n; j++) {
            for (map <int, int> :: iterator now = v[j].begin(); now != v[j].end(); now++) {
                for (int h = 0; h < now->second; h++) {
                    dp[now->first][i + 1] = (dp[now->first][i + 1] + dp[j][i])%mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= maxdepth; j++) {
            if (term[i]) {
                ans = (ans + dp[i][j])%mod;
            }
        }
    }
    cout << ans;
    return 0;
}
