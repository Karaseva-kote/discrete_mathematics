#include <bits/stdc++.h>

using namespace std;

int n;
long long f;
vector <int> p;
bool used[20];

int countNotUsed(int num) {
    int cnt = 0;
    for (int i = 1; i < num; i++) {
        if (!used[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        p.push_back(b);
    }
    f = 1;
    for (int i = 2; i < n; i++)
        f *= i;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int c = countNotUsed(p[i]);
        used[p[i]] = 1;
        ans += (c*f);
        f /= (n - 1 - i);
    }
    cout << ans;
    return 0;
}
