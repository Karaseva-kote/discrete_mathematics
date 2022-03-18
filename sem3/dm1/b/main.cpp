#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<bool> > mtx(n, vector<bool>(n, 0));
    for (int i = 1; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < i; j++) {
            if (a[j] == '1') {
                mtx[i][j] = 1;
                mtx[j][i] = 1;
            }
        }
    }
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        deq.push_back(i);
    }
    for (int k = 0; k < n*(n - 1); k++) {
        int v1 = deq.front();
        deq.pop_front();
        int v2 = deq.front();
        int u = 2;
        if (!mtx[v1][v2]) {
            deque<int>::iterator i = deq.begin();
            vector<int> pref;
            pref.push_back(*i);
            ++i;
            while (!mtx[v1][*i] || !mtx[v2][*(i + 1)]) {
                pref.push_back(*i);
                ++i;
                ++u;
                if (u == n - 1) {
                    i = deq.begin();
                    pref.clear();
                    while(!mtx[v1][*i]) {
                        pref.push_back(*i);
                        ++i;
                    }
                    break;
                }
            }
            pref.push_back(*i);
            for (int j = 0; j < pref.size(); j++) {
                deq.pop_front();
            }
            for (int j = 0; j < pref.size(); j++) {
                deq.push_front(pref[j]);
            }
        }
        deq.push_back(v1);
    }

    for (deque<int>::iterator now = deq.begin(); now != deq.end(); ++now) {
        cout << *now + 1 << " ";
    }
    return 0;
}
