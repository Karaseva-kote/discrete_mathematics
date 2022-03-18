#include <bits/stdc++.h>

using namespace std;

long long k;
vector<long long> first, recurrent, q, p;

void denominator() {
    q.push_back(1);
    for(long long i = 0; i < k; i++) {
        q.push_back(-recurrent[i]);
    }
}

void numerator() {
    for (long long i = 0; i < k; i++) {
        long long sum = 0;
        for(long long j = 0; j <= i; j++) {
            sum += first[j]*q[i - j];
        }
        p.push_back(sum);
    }
    while(p.back() == 0) {
        p.erase(--p.end());
    }
}

int main()
{
    cin >> k;
    for(long long i = 0; i < k; i++) {
        long long a;
        cin >> a;
        first.push_back(a);
    }
    for(long long i = 0; i < k; i++) {
        long long a;
        cin >> a;
        recurrent.push_back(a);
    }
    denominator();
    numerator();
    cout << p.size() - 1 << endl;
    for (long long i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }
    cout << endl << q.size() - 1 << endl;
    for (long long i = 0; i < q.size(); i++) {
        cout << q[i] << " ";
    }
    return 0;
}
