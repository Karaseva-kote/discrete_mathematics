#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<bool> > graph;
vector<int> ans;

void topsort() {
    for (int i = 1; i < n; i++) {
        bool flag = 1;
        for (int j = 0; j < ans.size(); j++) {
            if (graph[i][ans[j]]) {
                ans.insert(ans.begin() + j, i);
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans.push_back(i);
        }
    }
}

int main()
{
    cin >> n;
    graph.resize(n, vector<bool>(n, 0));
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < i; j++) {
            if (s[j] == '1') {
                graph[i][j] = 1;
            } else {
                graph[j][i] = 1;
            }
        }
    }
    ans.push_back(0);
    topsort();
    int pos = -1;
    for (int i = 2; i < n; i++) {
        if (graph[ans[i]][ans[0]]) {
            pos = i;
        }
    }
    pos++;
    int len = pos;
    vector<int> cycle;
    for (int i = pos; i < n; i++) {
        cycle.push_back(ans[i]);
        int place = -1;
        for (int j = 0; j < len; j++) {
            if (graph[ans[i]][ans[j]]) {
                vector<int>::iterator iter = ans.begin() + j;
                ans.insert(iter, cycle.begin(), cycle.end());
                len += cycle.size();
                iter = ans.begin() + len;
                vector<int>::iterator iter2 = ans.begin() + len + cycle.size();
                ans.erase(iter, iter2);
                cycle.clear();
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
