#include <bits/stdc++.h>

using namespace std;

const long long mod = 104857601;

int main()
{
    long long k, n;
    cin >> k >> n;
    n--;
    vector<long long> a(2*k);
    for(long long i = 0; i < k; i++) {
        cin >> a[i];
    }
    vector<long long> c(k);
    for(long long i = 0; i < k; i++) {
        cin >> c[i];
    }
    vector<long long> q(k + 1);
    q[0] = 1;
    for(long long i = 1; i <= k; i++) {
        q[i] = (mod - c[i - 1]);
    }
    while(n >= k) {
        for(long long i = k; i < 2*k; i++) {
            long long sum = 0;
            for(long long j = 1; j <= k; j++) {
                sum = ((sum - q[j]*a[i - j])%mod + mod)%mod;
            }
            a[i] = sum;
        }
        vector<long long> r(2*k + 1, 0);
        for(long long i = 0; i <= k; i++) {
            for(long long j = 0; j <= k; j++) {
                long long Q = q[j];
                if(j%2) {
                    Q = mod - Q;
                }
                r[i + j] = (r[i + j] + (q[i]*Q)%mod)%mod;
            }
        }
        for(long long i = n%2; i < 2*k; i += 2) {
            a[i/2] = a[i];
        }
        for(long long i = 0; i <= 2*k; i += 2) {
            q[i/2] = r[i];
        }
        n /= 2;
    }
    cout << a[n];
    return 0;
}
