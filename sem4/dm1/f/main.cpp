#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    long long k, m;
    cin >> k >> m;
    vector<bool> nodes(m + 1, 0);
    for(long long i = 0; i < k; i++) {
        long long a;
        cin >> a;
        nodes[a] = 1;
    }
    vector<long long> trees(m + 1);
    vector<long long> sumOfSubtrees(m + 1, 0);
    trees[0] = 1;
    sumOfSubtrees[0] = 1;
    for(long long i = 1; i <= m; i++) {
        long long sum = 0;
        for (long long j = 1; j <= i; j++) {
            if(nodes[j]) {
                sum = (sum + sumOfSubtrees[i - j])%mod;
            }
        }
        trees[i] = sum;
        for(long long j = 0; j <= i; j++) {
            sumOfSubtrees[i] = (sumOfSubtrees[i] + (trees[j]*trees[i - j])%mod)%mod;
        }
    }
    for(long long i = 1; i <= m; i++) {
        cout << trees[i] << " ";
    }
    return 0;
}
