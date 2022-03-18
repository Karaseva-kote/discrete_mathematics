#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<bool> term(n, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x - 1] = 1;
    }
    vector<vector < vector<int> > > nka(26, vector< vector<int> >(n, vector<int>()));
    for (int i = 0; i < m; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        nka[c - 'a'][from - 1].push_back(to - 1);
    }
    queue< set<int> > q;
    map< set<int>, int > past;
    set<int> start;
    start.insert(0);
    q.push(start);
    past.insert(pair< set<int>, int >(start, 0));
    vector< vector<int> > dna(1, vector<int>());
    vector<bool> term2;
    term2.push_back(term[0]);
    int num = 1;
    while(!q.empty()) {
        set<int> from = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            bool ter = false;
            set<int> to;
            for (set <int> :: iterator now = from.begin(); now != from.end(); now++) {
                for (int h = 0; h < nka[i][*now].size(); h++) {
                    to.insert(nka[i][*now][h]);
                    if (term[nka[i][*now][h]]) {
                        ter = true;
                    }
                }

            }
            if (!to.empty()) {
                if (past.find(to) == past.end()) {
                    dna[past.at(from)].push_back(num);
                    past.insert(pair< set<int>, int >(to, num));
                    dna.push_back(vector<int>());
                    term2.push_back(ter);
                    q.push(to);
                    num++;
                } else {
                    dna[past.at(from)].push_back(past.at(to));
                }
            }
        }
    }
    vector< vector<long long> > dp(dna.size(), vector<long long>(l + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < dna.size(); j++) {
            for (int h = 0; h < dna[j].size(); h++) {
                dp[dna[j][h]][i + 1] = (dp[dna[j][h]][i + 1] + dp[j][i])%mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < dna.size(); i++) {
        if (term2[i]) {
            ans = (ans + dp[i][l])%mod;
        }
    }
    cout << ans;
    return 0;
}
