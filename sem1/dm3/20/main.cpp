#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
long long dp[N][N];
string s;
stack <char> st;

long long getNo() {
    long long num = 0;
    int bal = 0;
    for (int i = 0 ; i < n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            bal++;
        }
        if (s[i] == ')') {
            int nbal = bal + 1;
            num += dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            if (st.top() == '(')
                st.pop();
            bal--;
        }
        if (s[i] == '[') {
            int nbal = bal + 1;
            num += dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            nbal = bal - 1;
            if (st.size() > 0) {
                if (st.top() == '(')
                    num += dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            }
            st.push(s[i]);
            bal++;
        }
        if (s[i] == ']') {
            int nbal = bal + 1;
            num += dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            nbal = bal + 1;
            num += dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            if (st.top() == '[')
                st.pop();
            bal--;
        }
        if (n - 1 - i - bal == 0)
            break;
    }
    return num;
 }

int main()
{
    freopen ("brackets2num2.in", "r", stdin);
    freopen ("brackets2num2.out", "w", stdout);
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
    cout << getNo();
    return 0;
}
