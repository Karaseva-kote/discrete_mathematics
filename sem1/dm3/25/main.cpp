#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int n, k, nx[N];

bool next() {
    nx[k] = n + 1;
    int i = k - 1;
    while (i >= 0 && nx[i + 1] - nx[i] < 2)
        i--;
    if (i >= 0) {
        nx[i]++;
        for (int j = i + 1; j < k; j++)
            nx[j] = nx[j - 1] + 1;
        return 1;
    }
    return 0;
}

int main()
{
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> nx[i];
    }
    if (next()){
        for (int i = 0; i < k; i++)
            cout << nx[i] << ' ';
    } else {
        cout << -1;
    }
    return 0;
}
