#include <bits/stdc++.h>

using namespace std;

int n, p[16];

void gener(int len){
    if (len == n){
        for (int i = 0; i < n; i++)
            cout << p[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < 2; i++){
        p[len] = i;
        gener(len + 1);
    }
}

int main()
{
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    cin >> n;
    gener(0);
    return 0;
}
