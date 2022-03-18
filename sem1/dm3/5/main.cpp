#include <bits/stdc++.h>

using namespace std;

int n, k, p[100];

void reverseCodeGray(int len);

void codeGray(int len) {
    if(len == 0){
        for(int i = 0; i < n; i++) {
            cout << p[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < k; i++){
        p[n - len] = i;
        if(i % 2 == 0)
            codeGray(len - 1);
        else
            reverseCodeGray(len - 1);
    }
}

void reverseCodeGray(int len) {
    if(len == 0){
        for(int i = 0; i < n; i++) {
            cout << p[i];
        }
        cout << endl;
        return;
    }
    for (int i = k - 1; i >= 0; i--){
        p[n - len] = i;
        if(i % 2 != 0)
            codeGray(len - 1);
        else
            reverseCodeGray(len - 1);
    }
}

int main()
{
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    cin >> n >> k;
    codeGray(n);
    return 0;
}
