#include <bits/stdc++.h>

using namespace std;

int n, p[16], cnt = 0;

void reverseCodeGray(int len);

void codeGray(int len) {
    if(len == 0){
        cout << cnt << "  ";
        cnt++;
        for(int i = 0; i < n; i++) {
            cout << p[i];
        }
        cout << endl;
        return;
    }
    p[n - len] = 0;
    codeGray(len - 1);
    p[n - len] = 1;
    reverseCodeGray(len - 1);
}

void reverseCodeGray(int len) {
    if(len == 0){
        cout << cnt << "  ";
        cnt++;
        for(int i = 0; i < n; i++) {
            cout << p[i];
        }
        cout << endl;
        return;
    }
    p[n - len] = 1;
    codeGray(len - 1);
    p[n - len] = 0;
    reverseCodeGray(len - 1);
}

int main()
{
    //freopen("gray.in", "r", stdin);
    //freopen("gray.out", "w", stdout);
    cin >> n;
    codeGray(n);
    return 0;
}
