#include <bits/stdc++.h>

using namespace std;

int n, bal;
char a[50];

void gen(int p, int bal) {
    if (p == n * 2) {
        if (bal == 0) {
            for (int i = 0; i < n * 2 ; i++)
                cout << a[i];
            cout << endl;
        }
        return;
    }
    a[p] = '(';
    gen(p + 1, bal + 1);
    if (bal != 0){
        a[p] = ')';
        gen(p + 1, bal - 1);
    }
 }

int main()
{
    //freopen ("brackets.in", "r", stdin);
    //freopen ("brackets.out", "w", stdout);
    cin >> n;
    gen(0, 0);
    return 0;
}
