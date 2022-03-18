#include <bits/stdc++.h>

using namespace std;

int n;
vector <bool> v[1050], f;
bool jeg[1050][1050];

void line (){
    for (int i = 0; i < f.size(); i++)
        jeg[0][i] = f[i];
    for (int i = 1; i < f.size(); i++){
        for (int j = 0; j < f.size() - i; j++){
            jeg[i][j] = (jeg[i-1][j] ^ jeg[i-1][j+1]);
        }
    }
}

int main()
{
    cin >> n;
    int c = 1 << n;
    for (int i = 0; i < c; i++){
        char r;
        for (int j = 0; j < n; j++){
            cin >> r;
            v[i].push_back(r - '0');
        }
        bool b;
        cin >> b;
        f.push_back(b);
    }
    line();
    for (int i = 0; i < c; i++){
        for (int j = 0; j < n; j++){
            cout << v[i][j];
        }
        cout << " " << jeg[i][0] << endl;
    }
    return 0;
}
