#include <bits/stdc++.h>

using namespace std;


const long long mod = 998244353;
const long long inverse2 = 499122177;
long long n;
int point;

vector<long long> sum(vector<long long> const &p, vector<long long> const &q) {
    vector<long long> res;
    for (long long i = 0; i <= max(p.size(), q.size()); i++) {
        long long a = 0, b = 0;
        if (i < p.size()) {
            a = p[i];
        }
        if (i < q.size()) {
            b = q[i];
        }
        res.push_back((a + b)%mod);
    }
    return res;
}

vector<long long> multiply(vector<long long> const &p, vector<long long> const &q) {
    vector<long long> res;

    long long temp;
    for (int i = 0; i <= min(point, static_cast<const int &> (p.size() + q.size() - 2)); ++i) {
        temp = 0;
        for (int j = max(0, i - int(q.size())); j <= i, j < p.size(); ++j){
            long long a = 0, b = 0;
            if (j < p.size()) {
                a = p[j];
            }
            if (i - j < q.size()) {
                b = q[i - j];
            }
            temp = (temp + a*b) % mod;
            if (temp < 0) {
                temp += mod;
            }
        }
        res.push_back(temp);
    }

    return res;
}

long long divDmod(long long x, long long D) {
    if (x < 0) {
        x = x % mod + mod;
    }
    while (x % D != 0) {
        x += mod;
    }
    return x / D;
}

void squart(vector<long long> const &p) {
    vector<long long> res;
    res.push_back(1);

    for (size_t i = 1; i < point; ++i) {
        long long sum = 0;
        for (int j = 1; j < i; j++) {
            sum = ((sum + (res[j]*res[i - j])%mod)%mod + mod)%mod;
        }
        sum = ((mod - sum)%mod + mod)%mod;
        if (i < p.size()) {
            sum = ((sum + p[i])%mod + mod)%mod;
        }
        res.push_back((sum*inverse2)%mod);
    }
    for(int i = 0; i < point; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void exp(vector<long long> const &p) {
    vector<long long> res;
    res.push_back(1);
    vector<long long> powered_p;
    powered_p.push_back(1);

    for (size_t i = 1; i < point; ++i) {
        powered_p = multiply(vector<long long>(1, divDmod(1, i)), powered_p);
        powered_p = multiply(powered_p, p);
        res = sum(res, powered_p);
    }
    for(int i = 0; i < point; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void ln(vector<long long> const &p) {
    vector<long long> res;
    res.push_back(0);
    vector<long long> powered_p;
    powered_p.push_back(1);

    for (size_t i = 1; i < point; ++i) {
        powered_p = multiply(powered_p, p);
        res = sum(res, multiply(vector<long long>(1, divDmod(i % 2 == 1 ? 1 : -1, i)), powered_p));
    }
    for(int i = 0; i < point; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> point;
    vector<long long> p(n + 1);
    vector<long long> p2(n + 1);
    for (size_t i = 0; i < n + 1; ++i) {
        cin >> p[i];
        p2[i] = p[i];
    }
    p2[0] = 1;
    squart(p2);
    exp(p);
    ln(p);
    return 0;
}
