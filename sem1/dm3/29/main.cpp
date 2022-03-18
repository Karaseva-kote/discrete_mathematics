#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> p;

int main()
{
    //freopen("nextpartition.in", "r", stdin);
    //freopen("nextpartition.out", "w", stdout);
    cin >> n;
    char b;
    int num;
    while (cin >> b) {
        cin >> num;
        p.push_back(num);
    }
    int sz = p.size();
    if (sz == 1) {
        cout << "No solution";
        return 0;
    }
    p[sz - 2]++;
    p[sz - 1]--;
    if (p[sz - 2] > p[sz - 1]) {
        p[sz - 2] += p[sz - 1];
        sz--;
    } else {
        while (p[sz - 1] >= 2*p[sz - 2]) {
            p.push_back(p[sz - 1] - p[sz - 2]);
            p[sz - 1] = p[sz - 2];
            sz++;
        }
    }
    cout << n << "=" << p[0];
    for (int i = 1; i < sz; i++) {
        cout << "+" << p[i];
    }
    return 0;
}
