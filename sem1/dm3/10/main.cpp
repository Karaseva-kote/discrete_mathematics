#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

void gener(int remains, int last){
    if (remains == 0){
        cout << v[0];
        for (int i = 1; i < v.size(); i++)
            cout << "+" << v[i];
        cout << endl;
        return;
    }
    for (int i = last; i <= remains; i++){
        v.push_back(i);
        gener(remains - i, i);
        v.erase(v.end() - 1);
    }
}

int main()
{
    //freopen("partition.in", "r", stdin);
    //freopen("partition.out", "w", stdout);
    cin >> n;
    gener(n, 1);
    return 0;
}
