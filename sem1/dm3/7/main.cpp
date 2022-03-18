#include <bits/stdc++.h>

using namespace std;

int n, p[10];
set<int> s;

void gener(int len){
    if (len == n){
        for (int i = 0; i < n; i++)
            cout << p[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (s.find(i) == s.end()) {
            s.insert(i);
            p[len] = i;
            gener(len + 1);
            s.erase(i);
        }
    }
}

int main()
{
    //freopen("permutations.in", "r", stdin);
    //freopen("permutations.out", "w", stdout);
    cin >> n;
    gener(0);
    return 0;
}
