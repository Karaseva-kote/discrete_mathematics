#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
long long dp[N][N], k;
string s;

string getStr(long long no) {
    string result = "";
    int bal = 0;
    for (int i = 0 ; i < n; i++) {
        if (dp[n - 1 - i][bal + 1] > no) {
            result += '(';
            bal++;
        }
        else {
            no -= dp[n - 1 - i][bal + 1];
            result += ')';
            bal--;
        }
    }
    return result;
 }

int main()
{
    //freopen ("num2brackets.in", "r", stdin);
    //freopen ("num2brackets.out", "w", stdout);
    cin >> n >> k;
    n *= 2;
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
    cout << getStr(k);
    return 0;
}
