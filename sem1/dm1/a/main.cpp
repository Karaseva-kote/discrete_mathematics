#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, number, lim = 1;
bool num[15];
set <pair<int, int> > s;

bool f (){
    set <pair<int, int> > :: iterator it = s.begin();
    for (int i = 0; it != s.end(); i++, it++){
        bool a, b;
        if (it->first < 0)
            a = !num[abs(it->first) - 1];
        else
            a = num[abs(it->first) - 1];
        if (it->second < 0)
            b = !num[abs(it->second) - 1];
        else
            b = num[abs(it->second) - 1];
        if ((a | b) == 0)
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        s.insert({a, b});
    }
    lim = lim << n;
    while (1) {
        if (f()){
            cout << "NO";
            return 0;
        }
        number++;
        if (number < lim){
            int j = 0;
            while (num[j]){
                num[j] = !num[j];
                j++;
            }
            num[j] = !num[j];
        } else
            break;
    }
    cout << "YES";
    return 0;
}
