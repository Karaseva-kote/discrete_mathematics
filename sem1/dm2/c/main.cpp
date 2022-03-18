#include <bits/stdc++.h>

using namespace std;

int al[30];

int main()
{
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
    for (int i = 0; i < 26; i++){
        al[i] = i + 1;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        cout << al[int(s[i] - 'a')] << ' ';
        if (al[int(s[i] - 'a')] != 1){
            for (int j = 0; j < 26; j++){
                if (al[j] < al[int(s[i] - 'a')]){
                    al[j]++;
                }
            }
            al[int(s[i] - 'a')] = 1;
        }
    }
    return 0;
}
