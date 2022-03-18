#include <bits/stdc++.h>

using namespace std;

int n;
set<vector<bool> > s;

int main()
{
    freopen ("chaincode.in", "r", stdin);
    freopen ("chaincode.out", "w", stdout);
    cin >> n;
    vector<bool> v;
    for (int i = 0; i < n; i++){
        v.push_back(0);
    }
    s.insert(v);
    while (1) {
        for (int i = 0; i < n; i++)
            cout << v[i];
        cout << endl;
        v.erase(v.begin());
        v.push_back(1);
        if (s.find(v) != s.end()){
            v.erase(v.end() - 1);
            v.push_back(0);
            if (s.find(v) != s.end())
                break;
        }
        s.insert(v);
    }
    return 0;
}
