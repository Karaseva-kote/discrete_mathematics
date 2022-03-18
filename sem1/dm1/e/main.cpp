#include <bits/stdc++.h>

using namespace std;

int n, m, cnt_leaf, f[30], dep[30];
bool leaf[30];
vector <int> in[30];
vector <bool> table[30], result;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        if (m == 0){
            leaf[i] = 1;
            dep[i] = 0;
            cnt_leaf++;
        } else {
            int max_dep = 0;
            for (int j = 0; j < m; j++){
                int e;
                cin >> e;
                if (dep[e] > max_dep)
                    max_dep = dep[e];
                in[i].push_back(e);
            }
            dep[i] = max_dep + 1;
            for (int j = 0; j < (1 << m); j++){
                bool b;
                cin >> b;
                table[i].push_back(b);
            }
        }
    }
    for (int i = 0; i < (1 << cnt_leaf); i++){
        int cnt = cnt_leaf;
        for (int j = 1; j <= n; j++){
            if (leaf[j]){
                cnt--;
                f[j] = ((i / (1 << cnt)) % 2);
            } else {
                int h = 0;
                for (int k = 0; k < in[j].size(); k++){
                    h = h*2 + f[in[j][k]];
                }
                f[j] = table[j][h];
            }
        }
        result.push_back(f[n]);
    }
    cout << dep[n] << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    return 0;
}
