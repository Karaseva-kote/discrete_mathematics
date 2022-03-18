#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
string s;
long long dp[N][N];
vector <int> p;

long long findNo() {
    long long no = 0;
    int sum = n;
    for (int i = 0; i < p.size(); i++) {
        int ind = 1;
        if (i > 0)
            ind = p[i - 1];
        for (int first = ind; first < p[i]; first++)
            no += dp[sum][first];
        sum -= p[i];
    }
    return no;
}

int main()
{
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    char b;
    int num;
    cin >> num;
    while (cin >> b) {
        n += num;
        p.push_back(num);
        cin >> num;
    }
    n += num;
    p.push_back(num);
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
    cout << findNo();
    return 0;
}
