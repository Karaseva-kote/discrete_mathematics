#include <bits/stdc++.h>

using namespace std;

string s;

string prev() {
    string pr = s;
    int i = pr.size() - 1;
    while(i >= 0) {
        if (pr[i] == '0') {
            pr[i] = '1';
            i--;
        } else {
            pr[i] = '0';
            break;
        }
    }
    if (i == -1)
        return "-";
    return pr;
}

string next() {
    string nx = s;
    reverse(nx.begin(), nx.end());
    int i = 0;
    while(i < s.size()) {
        if (nx[i] == '1') {
            nx[i] = '0';
            i++;
        } else {
            nx[i] = '1';
            break;
        }
    }
    if (i == s.size())
        //nx += '1';
        return "-";
    reverse(nx.begin(), nx.end());
    return nx;
}

int main()
{
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    cin >> s;
    cout << prev() << endl << next();
    return 0;
}
