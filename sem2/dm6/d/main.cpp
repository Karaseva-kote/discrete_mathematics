#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    int n;
    char start;
    cin >> n >> start;
    vector<vector<char> > productions(n, vector<char>());
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        char from = line[0];
        productions[i].push_back(from);
        for (int y = 5; y < line.size(); y++) {
            productions[i].push_back(line[y]);
        }
    }
    string str;
    cin >> str;
    int sz = str.size();
    vector<vector<vector<long long> > > dp(26, vector<vector<long long> >(sz, vector<long long>(sz, 0)));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < n; j++) {
            if (productions[j].size() == 2) {
                if (productions[j][1] == str[i]) {
                    dp[productions[j][0] - 'A'][i][i] = 1;
                }
            }
        }
    }
    for (int len = 1; len < sz; len++) {
        for (int from = 0; from + len < sz; from++) {
            for (int i = 0; i < n; i++) {
                if (productions[i].size() == 3) {
                    for (int k = from; k < from + len; k++) {
                        dp[productions[i][0] - 'A'][from][from + len] = (dp[productions[i][0] - 'A'][from][from + len] +
                                                                         (dp[productions[i][1] - 'A'][from][k] *
                                                                         dp[productions[i][2] - 'A'][k + 1][from + len])%mod)%mod;
                    }
                }
            }
        }
    }
    cout << dp[start - 'A'][0][sz - 1];
    return 0;
}
