#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, INF = 1e6;
int n, nx[N];

bool next() {
    for (int i = n - 2; i >= 0; i--) {
        if (nx[i] < nx[i + 1]) {
            int Min = INF, ind = 0;
            for (int j = i + 1; j < n; j++) {
                if (nx[j] <= Min && nx[j] > nx[i]) {
                    Min = nx[j];
                    ind = j;
                }
            }
            swap(nx[i], nx[ind]);
            for (int j = i + 1; j <= (i + n)/2; j++) {
                swap(nx[j], nx[n + i - j]);
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nx[i];
    }
    if (next()){
        for (int i = 0; i < n; i++)
            cout << nx[i] << ' ';
    } else {
        for (int i = 0; i < n; i++)
            cout << "0 ";
    }
    return 0;
}
