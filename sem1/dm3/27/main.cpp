#include <bits/stdc++.h>

using namespace std;

string s;

string next() {
    int n = s.size(), op = 0, cl = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            op++;
            if (cl > op)
                break;
        } else
            cl++;
    }
    if (n - op - cl == 0)
        return "-";
    int ind = n - op - cl;
    s[ind] = ')';
    for (int i = 1; i <= op; i++)
        s[ind + i] = '(';
    ind += op;
    for (int i = 1; i < cl; i++)
        s[ind + i] = ')';
    return s;
}

int main()
{
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    cin >> s;
    cout << next();
    return 0;
}
