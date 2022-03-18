#include <bits/stdc++.h>

using namespace std;

int n, s;
vector <bool> tab_i[1010];
vector <int> len, t;
bool full[5], answer = 0, jeg[100][100];

bool save0 (int ind){
    return !tab_i[ind][0];
}

bool save1 (int ind){
    return tab_i[ind][tab_i[ind].size() - 1];
}

bool self_dual (int ind){
    for (int i = 0; i < ((tab_i[ind].size())/2); i++){
        if (tab_i[ind][i] == tab_i[ind][tab_i[ind].size() - i - 1])
            return 0;
    }
    return 1;
}

bool monoton (int ind){
    int shft = (tab_i[ind].size() / 2);
    for (int i = 0; i < len[ind]; i++){
        for(int j = 0; j < ((tab_i[ind].size() / shft)/2); j++){
            for (int k = j*shft*2; k < (j*shft*2 + shft); k++){
                if (tab_i[ind][k] > tab_i[ind][k + shft])
                    return 0;
            }
        }
        shft = shft/2;
    }
    return 1;
}

bool line (int ind){
    for (int i = 0; i < tab_i[ind].size(); i++)
        jeg[0][i] = tab_i[ind][i];
    for (int i = 1; i < tab_i[ind].size(); i++){
        for (int j = 0; j < tab_i[ind].size() - i; j++){
            jeg[i][j] = (jeg[i-1][j] ^ jeg[i-1][j+1]);
        }
        if ((t[i] > 1) && jeg[i][0])
            return 0;
    }
    return 1;
}

int main()
{
    for(int i = 0; i < 100; i++){
        int x = i;
        int cnt = 0;
        while(x > 0){
            if (x % 2 == 1)
                cnt++;
            x /= 2;
        }
        t.push_back(cnt);
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        len.push_back(s);
        if (s > 0){
            int c = 1 << s;
            for (int j = 0; j < c; j++){
                char r;
                cin >> r;
                tab_i[i].push_back(r - '0');
            }
            if (!save0(i))
                full[0] = 1;
            if (!save1(i))
                full[1] = 1;
            if (!self_dual(i))
                full[2] = 1;
            if (!monoton(i))
                full[3] = 1;
            if (!line(i))
                full[4] = 1;
            /*cout << save0(i) << endl;
            cout << save1(i) << endl;
            cout << self_dual(i) << endl;
            cout << monoton(i) << endl;
            cout << line(i) << endl;*/
        } else {
            bool r;
            cin >> r;
            if (r){
                full[0] = 1;
            } else{
                full[1] = 1;
            }
            full[2] = 1;
        }
        bool ans = 1;
        for (int j = 0; j < 5; j++){
            if (full[j] == 0){
                ans = 0;
                break;
            }
        }
        if (ans){
            answer = 1;
        }
    }
    if (answer)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
