#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > graph;
vector<bool> used;
vector<int> colors;
int maxDegree = 0;

void dfs(int v) {
    used[v] = 1;
    set<int> usedColors;
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if (colors[u] != 0) {
            usedColors.insert(colors[u]);
        }
    }
    int col = 1;
    while(usedColors.find(col) != usedColors.end()) {
        col++;
    }
    colors[v] = col;
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main()
{
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    used.resize(n, 0);
    colors.resize(n, 0);
    for (int i = 0; i < n; i++) {
        maxDegree = max(maxDegree, (int) graph[i].size());
        if (!used[i]) {
            dfs(i);
        }
    }
    maxDegree += (maxDegree + 1)%2;
    cout << maxDegree << endl;
    for (int i = 0; i < n; i++) {
        cout << colors[i] << endl;
    }
    return 0;
}
