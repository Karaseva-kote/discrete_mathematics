#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
long long dp[N][N];
string s;

long long getNo() {
    long long num = 0;
    int bal = 0;
    for (int i = 0 ; i < n; i++) {
        if (s[i] == '(')
            bal++;
        else {
            num += dp[n - 1 - i][bal + 1];
            bal--;
        }
    }
    return num;
 }

int main()
{
    freopen ("brackets2num.in", "r", stdin);
    freopen ("brackets2num.out", "w", stdout);
    cin >> s;
    n = s.size();
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long lastopen = 0, lastclose = 0;
            if (j - 1 >= 0)
                lastopen = dp[i - 1][j - 1];
            if (j + 1 < n)
                lastclose = dp[i - 1][j + 1];
            dp[i][j] = lastopen + lastclose;
        }
    }
    long long ans = getNo();
    cout << ans;
    return 0;
}
