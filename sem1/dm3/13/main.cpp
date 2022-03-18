#include <bits/stdc++.h>

using namespace std;

int n;
long long k, f;
vector <int> p;
bool used[20];

int getNotUsed(int no) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i])
            num++;
        if (num == no)
            return i;
    }
}

int main()
{
    //freopen("num2perm.in", "r", stdin);
    //freopen("num2perm.out", "w", stdout);
    cin >> n >> k;
    f = 1;
    for (int i = 2; i < n; i++)
        f *= i;
    long long start = k;
    for (int i = n - 1; i > 0; i--) {
        int next = start/f + 1;
        next = getNotUsed(next);
        used[next] = 1;
        p.push_back(next);
        start = start%f;
        f /= i;
    }
    p.push_back(getNotUsed(1));
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << ' ';
    }
    return 0;
}
