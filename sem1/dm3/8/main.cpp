#include <bits/stdc++.h>

using namespace std;

int n, k, p[20];

void gener(int len, int last){
    if (len == k){
        for (int i = 0; i < k; i++)
            cout << p[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = last + 1; i <= n; i++){
        p[len] = i;
        gener(len + 1, i);
    }
}

int main()
{
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    cin >> n >> k;
    gener(0, 0);
    return 0;
}
