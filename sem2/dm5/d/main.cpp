#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<bool> term(n, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = 1;
    }
    vector<vector <int> > v(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v[from - 1].push_back(to - 1);
    }
    vector< vector<long long> > dp(n, vector<long long>(l + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int h = 0; h < v[j].size(); h++) {
                dp[v[j][h]][i + 1] = (dp[v[j][h]][i + 1] + dp[j][i])%mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (term[i]) {
            ans = (ans + dp[i][l])%mod;
        }
    }
    cout << ans;
    return 0;
}
