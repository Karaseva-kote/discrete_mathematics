#include <bits/stdc++.h>

using namespace std;

int n, p[20], dp[2][20];

void gener(int len){
    if (len == n){
        for (int i = 0; i < n; i++)
            cout << p[i];
        cout << endl;
        return;
    }
    if (len == 0) {
        for (int i = 0; i < 2; i++){
            p[len] = i;
            gener(len + 1);
        }
    } else {
        if (p[len - 1] == 0){
            for (int i = 0; i < 2; i++){
                p[len] = i;
                gener(len + 1);
            }
        } else {
            p[len] = 0;
            gener(len + 1);
        }
    }
}

int main()
{
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin >> n;
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++){
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
    cout << dp[0][n] + dp[1][n] << endl;
    gener(0);
    return 0;
}
