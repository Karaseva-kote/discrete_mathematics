#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, INF = 1e6;
int n, p[N], pr[N], nx[N];

bool prev() {
    for (int i = n - 2; i >= 0; i--) {
        if (pr[i] > pr[i + 1]) {
            int Max = 0, ind = 0;
            for (int j = i + 1; j < n; j++) {
                if (pr[j] > Max && pr[j] < pr[i]) {
                    Max = pr[j];
                    ind = j;
                }
            }
            swap(pr[i], pr[ind]);
            for (int j = i + 1; j <= (i + n)/2; j++) {
                swap(pr[j], pr[n + i - j]);
            }
            return 1;
        }
    }
    return 0;
}

bool next() {
    for (int i = n - 2; i >= 0; i--) {
        if (nx[i] < nx[i + 1]) {
            int Min = INF, ind = 0;
            for (int j = i + 1; j < n; j++) {
                if (nx[j] < Min && nx[j] > nx[i]) {
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
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pr[i] = p[i];
        nx[i] = p[i];
    }
    if (prev()){
        for (int i = 0; i < n; i++)
            cout << pr[i] << ' ';
    } else {
        for (int i = 0; i < n; i++)
            cout << "0 ";
    }
    cout << endl;
    if (next()){
        for (int i = 0; i < n; i++)
            cout << nx[i] << ' ';
    } else {
        for (int i = 0; i < n; i++)
            cout << "0 ";
    }
    return 0;
}
