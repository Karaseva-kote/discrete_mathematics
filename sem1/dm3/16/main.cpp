#include <bits/stdc++.h>

using namespace std;

int n, k;
long long no, choose;
bool take[40];

int main()
{
    //freopen("choose2num.in", "r", stdin);
    //freopen("choose2num.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int buf;
        cin >> buf;
        take[buf] = 1;
    }
    choose = 1;
    for (int i = k + 1; i <= n; i++)
        choose = (choose*i)/(i - k);
    int n1 = n, k1 = k;
    for (int i = 1; i <= n; i++) {
        long long newChoose = (choose*k1)/n1;
        if (!take[i]) {
            no += newChoose;
            cout << i << " " << newChoose << endl;
            choose = (choose*(n1 - k1))/n1;
            n1--;
        } else {
            choose = newChoose;
            k1--;
            n1--;
        }
        if (k1 == 0)
            break;
    }
    cout << no;
    return 0;
}
