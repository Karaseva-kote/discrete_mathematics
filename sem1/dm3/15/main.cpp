#include <bits/stdc++.h>

using namespace std;

int n, k;
long long no, choose;
bool take[40];

int main()
{
    //freopen("num2choose.in", "r", stdin);
    //freopen("num2choose.out", "w", stdout);
    cin >> n >> k >> no;
    choose = 1;
    for (int i = k + 1; i <= n; i++)
        choose = (choose*i)/(i - k);
    long long start = no;
    int n1 = n, k1 = k;
    for (int i = 1; i <= n; i++) {
        long long newChoose = (choose*k1)/n1;
        if (start < newChoose){
            choose = newChoose;
            k1--;
            n1--;
            take[i] = 1;
        } else {
            start -= newChoose;
            choose = (choose*(n1 - k1))/n1;
            n1--;
        }
        if (k1 == 0)
            break;
    }
    for (int i = 1; i <= n; i++) {
        if (take[i])
            cout << i << ' ';
    }
    return 0;
}
