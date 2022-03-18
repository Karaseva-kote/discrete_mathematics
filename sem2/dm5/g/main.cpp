#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int v1[N][26], v2[N][26];
int n1, m1, k1, n2, m2, k2;
bool term1[N], term2[N], used[N][N];

bool bfs() {
    queue< pair<int, int> > q;
    q.push(pair<int, int>(1, 1));
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (term1[curr.first] != term2[curr.second]) {
            return 0;
        }
        used[curr.first][curr.second] = 1;
        for (int i = 0; i < 26; i++) {
            if (!used[v1[curr.first][i]][v2[curr.second][i]]) {
                q.push(pair<int, int>(v1[curr.first][i], v2[curr.second][i]));
            }
        }
    }
    return 1;
}

int main()
{
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    cin >> n1 >> m1 >> k1;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        term1[x] = 1;
    }
    for (int i = 0; i < m1; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v1[from][c - 'a'] = to;
    }
    cin >> n2 >> m2 >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        term2[x] = 1;
    }
    for (int i = 0; i < m2; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v2[from][c - 'a'] = to;
    }
    if (bfs()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
