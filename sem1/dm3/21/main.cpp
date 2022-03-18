#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
long long r, dp[N][N];
vector <int> p;

void findPart(long long no) {
    int sum = n, part = 1;
    while (sum != 0) {
        if (dp[sum][part] <= no) {
            no -= dp[sum][part];
            part++;
        } else {
            p.push_back(part);
            sum -= part;
        }
    }
}

int main()
{
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    cin >> n >> r;
    dp[1][1] = 1;
    for (int sum = 2; sum <= n; sum++) {
        for (int first = 1; first <= sum; first++) {
            if (sum - first == 0) {
                dp[sum][first] = 1;
            } else if (sum - first >= first) {
                for (int i = first; i <= sum - first; i++)
                    dp[sum][first] += dp[sum - first][i];
            }
        }
    }
    findPart(r);
    cout << p[0];
    for (int i = 1; i < p.size(); i++) {
        cout << "+" << p[i];
    }
    return 0;
}
