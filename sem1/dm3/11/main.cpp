#include <bits/stdc++.h>

using namespace std;

int n, p[16];

void gener(int len, int last){
    if (len == 1){
        p[last + 1] = 1;
        for (int i = 0; i < n; i++){
            if (p[i] == 1)
                cout << i+1 << ' ';
        }
        cout << endl;
        return;
    }
    p[last + 1] = 1;
    for (int i = 0; i < last + 2; i++){
        if (p[i] == 1)
            cout << i+1 << ' ';
    }
    for (int i = last + 2; i < n; i++) {
        p[i] = 0;
    }
    cout << endl;
    gener(len - 1, last + 1);
    p[last + 1] = 0;
    gener(len - 1, last + 1);
}

int main()
{
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin >> n;
    cout << endl;
    gener(n, -1);
    return 0;
}
