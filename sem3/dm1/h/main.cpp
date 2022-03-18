#include <bits/stdc++.h>

using namespace std;

int n, m;
set<pair<int, int> > edge;

void deleteEdge(pair<int, int> a) {
    edge.erase(a);
    edge.erase({a.second, a.first});
}

void addEdge(pair<int, int> a) {
    edge.insert(a);
    edge.insert({a.second, a.first});
}

void deleteVer(pair<int, int> a,
               vector<int> &b2,
               vector<int> &b1) {
    for(int i = 0 ; i < n; i++) {
        if(edge.find({a.second, i}) != edge.end()) {
            b2.push_back(i);
            if (i != a.first && edge.find({a.first, i}) == edge.end()) {
                edge.insert({a.first, i});
                edge.insert({i, a.first});
                b1.push_back(i);
            }
            edge.erase({a.second, i});
            edge.erase({i, a.second});
        }
    }
}

void addVer(pair<int, int> a,
               vector<int> &b2,
               vector<int> &b1) {
    for (int i = 0; i < b1.size(); i++) {
        edge.erase({a.first, b1[i]});
        edge.erase({b1[i], a.first});
    }
    for (int i = 0; i < b2.size(); i++) {
        edge.insert({a.second, b2[i]});
        edge.insert({b2[i], a.second});
    }
}

vector<int> chrom(int c) {
    vector<int> p(n + 1, 0);
    if (edge.empty()) {
        p[c] = 1;
        return p;
    }
    pair<int, int> a = *edge.begin();
    deleteEdge(a);
    vector<int> p1 = chrom(c);
    addEdge(a);
    vector<int> b1;
    vector<int> b2;
    deleteVer(a, b2, b1);
    vector<int> p2 = chrom(c - 1);
    addVer(a, b2, b1);
    for (int i = 0; i <= n; i++) {
        p[i] = p1[i] - p2[i];
    }
    return p;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge.insert({a - 1, b - 1});
        edge.insert({b - 1, a - 1});
    }
    vector<int> result = chrom(n);
    cout << n << endl;
    for(int i = n; i >= 0; i--) {
        cout << result[i] << " ";
    }
    return 0;
}
