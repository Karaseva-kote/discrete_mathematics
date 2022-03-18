#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
long long n, m;
vector<long long> p, q;

void sum() {
    cout << max(n, m) << endl;
    for (long long i = 0; i <= max(n, m); i++) {
        long long a = 0, b = 0;
        if (i <= n) {
            a = p[i];
        }
        if (i <= m) {
            b = q[i];
        }
        cout << (a + b)%mod << " ";
    }
    cout << endl;
}

void multiply() {
    cout << n + m << endl;
    vector<long long> ans(n + m + 1, 0);
    for(long long i = 0; i <= n; i++) {
        for (long long j = 0; j <= m; j++) {
            ans[i + j] = (ans[i + j] + ((p[i]*q[j])%mod))%mod;
        }
    }
    for (long long i = 0; i <= n + m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void divide() {
    vector<long long> inverseQ(1, 1);
    for(long long i = 1; i < 1000; i++) {
        long long sum = 0;
        for(long long j = 1; j <= i; j++) {
            long long Q = 0;
            if(j <= m) {
                Q = q[j];
            }
            sum = (sum + (Q*inverseQ[i - j])%mod)%mod;
        }
        inverseQ.push_back((-sum + mod)%mod);
    }
    for(long long i = 0; i < 1000; i++) {
        long long ans = 0;
        for(long long j = 0; j <= i; j++) {
            long long P = 0;
            if (j <= n) {
                P = p[j];
            }
            ans = (ans + (P*inverseQ[i - j])%mod)%mod;
        }
        cout << ans << " ";
    }
}

int main()
{
    cin >> n >> m;
    for(long long i = 0; i <= n; i++) {
        long long a;
        cin >> a;
        p.push_back(a);
    }
    for(long long i = 0; i <= m; i++) {
        long long a;
        cin >> a;
        q.push_back(a);
    }
    sum();
    multiply();
    divide();
    return 0;
}
