#include <bits/stdc++.h>

using namespace std;

int n, p[10], a[10];

void antiGray(int len){
    if (len == n - 1){
        for (int i = 0; i < n; i++){
            cout << p[i];
            a[i] = (p[i] + 1)%3;
        }
        cout << endl;
        for (int i = 0; i < n; i++){
            cout << a[i];
            a[i] = (a[i] + 1)%3;
        }
        cout << endl;
        for (int i = 0; i < n; i++){
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < 3; i++){
        p[len] = i;
        antiGray(len + 1);
    }
}

int main()
{
    freopen ("antigray.in", "r", stdin);
    freopen ("antigray.out", "w", stdout);
    cin >> n;
    antiGray(0);
    return 0;
}
