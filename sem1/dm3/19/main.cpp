#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
long long dp[N][N], k;
stack <char> st;

string getStr(long long no) {
    string s = "";
    int bal = 0;
    for (int i = 0 ; i < n; i++) {
        int nbal = bal + 1;
        if (dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2)) > no) {
            s += '(';
            st.push('(');
            bal++;
        } else {
            no -= dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
            nbal = bal - 1;
            if (st.size() > 0) {
                if (st.top() == '(') {
                    if (dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2)) > no) {
                        s += ')';
                        if (st.top() == '(')
                            st.pop();
                        bal--;
                    } else {
                        no -= dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
                        nbal = bal + 1;
                        if (dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2)) > no) {
                            s += '[';
                            st.push('[');
                            bal++;
                        } else {
                            no -= dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
                            s += ']';
                            if (st.top() == '[')
                                st.pop();
                            bal--;
                        }
                    }
                } else {
                    nbal = bal + 1;
                    if (dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2)) > no) {
                        s += '[';
                        st.push('[');
                        bal++;
                    } else {
                        no -= dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
                        s += ']';
                        if (st.top() == '[')
                            st.pop();
                        bal--;
                    }
                }
            } else {
                nbal = bal + 1;
                if (dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2)) > no) {
                    s += '[';
                    st.push('[');
                    bal++;
                } else {
                    no -= dp[n - 1 - i][nbal]*(1<<((n - 1 - i - nbal)/2));
                    s += ']';
                    if (st.top() == '[')
                        st.pop();
                    bal--;
                }
            }
        }
        if (n - 1 - i - bal == 0)
            break;
    }
    while(!st.empty()) {
        if (st.top() == '(')
            s += ')';
        else
            s += ']';
        st.pop();
    }
    return s;
 }

int main()
{
    freopen ("num2brackets2.in", "r", stdin);
    freopen ("num2brackets2.out", "w", stdout);
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
