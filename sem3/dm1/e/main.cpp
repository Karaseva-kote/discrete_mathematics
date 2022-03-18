#include <bits/stdc++.h>

using namespace std;

void dfs (int v,
          vector<int> &parent,
          vector<vector<int> > &graph) {
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u, parent, graph);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > graph(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    vector<int> parent(n);
    parent[n - 1] = -1;
    dfs(n - 1, parent, graph);
    vector<int> degree(n);
    int ptr = -1;
    for (int i = 0; i < n; i++) {
        degree[i] = graph[i].size();
        if (degree[i] == 1 && ptr == -1) {
            ptr = i;
        }
    }
    int leaf = ptr;
    vector<int> ans;
    for(int i = 0; i < n - 2; i++){
        int p = parent[leaf];
        ans.push_back(p);
        degree[p]--;
        if (degree[p] == 1 && p < ptr) {
            leaf = p;
        } else {
            ptr++;
            while(ptr < n && degree[ptr] != 1) {
                ptr++;
            }
            leaf = ptr;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
