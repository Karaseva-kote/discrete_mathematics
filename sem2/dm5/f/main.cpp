#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
map<int, int> bijection1, bijection2;
map<char, int> v1[N], v2[N];
int n1, m1, k1, n2, m2, k2;
bool term1[N], term2[N], used1[N], used2[N];

bool bfs1() {
    queue<int> q;
    q.push(0);
    used1[0] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (map <char, int> :: iterator now = v1[curr].begin(); now != v1[curr].end(); now++) {
            if (v2[bijection1.at(curr)].find(now->first) == v2[bijection1.at(curr)].end()) {
                return 0;
            }
            if (term1[now->second] != term2[v2[bijection1.at(curr)].at(now->first)]) {
                return 0;
            }
            if (!used1[now->second]) {
                q.push(now->second);
                used1[now->second] = 1;
            }
            bijection1.insert(pair<int, int>(now->second, v2[bijection1.at(curr)].at(now->first)));
        }
    }
    return 1;
}

bool bfs2() {
    queue<int> q;
    q.push(0);
    used2[0] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (map <char, int> :: iterator now = v2[curr].begin(); now != v2[curr].end(); now++) {
            if (v1[bijection2.at(curr)].find(now->first) == v1[bijection2.at(curr)].end()) {
                return 0;
            }
            if (term2[now->second] != term1[v1[bijection2.at(curr)].at(now->first)]) {
                return 0;
            }
            if (!used2[now->second]) {
                q.push(now->second);
                used2[now->second] = 1;
            }
            bijection2.insert(pair<int, int>(now->second, v1[bijection2.at(curr)].at(now->first)));
        }
    }
    return 1;
}

int main()
{
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    cin >> n1 >> m1 >> k1;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        term1[x - 1] = 1;
    }
    for (int i = 0; i < m1; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v1[from - 1].insert(pair<char, int>(c, to - 1));
    }
    cin >> n2 >> m2 >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        term2[x - 1] = 1;
    }
    for (int i = 0; i < m2; i++) {
        int from, to;
        char c;
        cin >> from >> to >> c;
        v2[from - 1].insert(pair<char, int>(c, to - 1));
    }
    if (n1 != n2) {
        cout << "NO";
        return 0;
    }
    bijection1.insert(pair<int, int>(0, 0));
    bijection2.insert(pair<int, int>(0, 0));
    if (bfs1() && bfs2()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
