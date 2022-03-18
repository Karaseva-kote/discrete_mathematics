#include <bits/stdc++.h>


const long long mod = 998244353;
int point;


using namespace std;

void print_vector(vector<long long> &v, int s) {
    for (size_t i = 1; i <= s; ++i) {
        if (i >= v.size()) {
            cout << 0 << endl;
        } else {
            cout << v[i] << endl;
        }
    }
}

vector<long long> fill(vector<long long> const &p, vector<long long> const &q) {
    vector<long long> res;
    for (size_t i = 0; i < max(p.size(), q.size() + 1); ++i) {
        long long temp;
        long long a = 0, b = 0;
        if (i < p.size()) {
            a = p[i];
        }
        if(i - 1 < q.size()) {
            b = q[i - 1];
        }
        if (i == 0) {
            temp = a%mod;
        } else {
            temp = ((a - b)%mod + mod)%mod;
        }
        res.push_back(temp);
    }

    return res;
}

vector<long long> multiply(vector<long long> const &p, vector<long long> const &q) {
    vector<long long> res;
    for (int i = 0; i <= min(point, static_cast<const int &>(p.size() + q.size() - 2)); ++i) {
        long long temp = 0;
        for (size_t j = 0; j <= i; ++j) {
            long long a = 0, b = 0;
            if (j < p.size()) {
                a = p[j];
            }
            if (i - j < q.size()) {
                b = q[i - j];
            }
            temp = ((temp + a * b) % mod + mod)%mod;
        }
        res.push_back(temp);
    }
    return res;
}

vector<long long> division(vector<long long> const &p, vector<long long> const &q) {
    vector<long long> res;

    vector<long long> buff = p;

    int cur_pos = 0;
    while (res.size() <= point) {
        if (buff.size() <= cur_pos) {
            buff.push_back(0);
        }
        long long next = (buff[cur_pos] % mod + mod)%mod;
        res.push_back(next);
        for (int i = cur_pos; i < min(point, static_cast<const int &>(cur_pos + q.size())); ++i) {
            if (buff.size() <= i) {
                buff.push_back(0);
            }
            buff[i] = ((buff[i] - (q[i - cur_pos] * next) % mod)%mod + mod)%mod;
        }
        cur_pos++;
    }
    return res;
}

int main() {
    int k, n;
    cin >> k >> n;
    point = n + 5;

    vector<long long> ans(2, 0);
    vector<long long> p(1, 1);
    vector<long long> q(1, 1);
    vector<long long> p_new, q_new;

    for (int i = 3; i <= k; ++i) {
        p_new = q;
        q_new = fill(q, p);
        p = p_new;
        q = q_new;
    }

    p_new.clear();
    q_new.clear();

    ans[1] = 1;
    if (k >= 3) {
        ans = division(multiply(vector<long long>{0, 1}, p), q);
    }
    print_vector(ans, n);
    return 0;
}
