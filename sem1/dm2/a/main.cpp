#include <bits/stdc++.h>

using namespace std;

vector <long long> el, node;
vector <vector<long long> > b;
long long ans;

int main()
{
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++){
        long long p;
        cin >> p;
        el.push_back(p);
    }
    sort(el.begin(), el.end());
    while (!(el.empty() && node.size() == 1)){
        long long sum = 0;
        vector <long long> c;
        if (!el.empty()){
            if (!node.empty()){
                if (el[0] < node[0]){
                    c.push_back(el[0]);
                    ans += el[0];
                    sum += el[0];
                    el.erase(el.begin());
                } else {
                    for (long long i = 0; i < b[0].size(); i++){
                        c.push_back(b[0][i]);
                        ans += b[0][i];
                        sum += b[0][i];
                    }
                    node.erase(node.begin());
                    b.erase(b.begin());
                }
            } else {
                c.push_back(el[0]);
                ans += el[0];
                sum += el[0];
                el.erase(el.begin());
            }
        } else {
            for (long long i = 0; i < b[0].size(); i++){
                c.push_back(b[0][i]);
                ans += b[0][i];
                sum += b[0][i];
            }
            node.erase(node.begin());
            b.erase(b.begin());
        }
        if (!el.empty()){
            if (!node.empty()){
                if (el[0] < node[0]){
                    c.push_back(el[0]);
                    ans += el[0];
                    sum += el[0];
                    el.erase(el.begin());
                } else {
                    for (long long i = 0; i < b[0].size(); i++){
                        c.push_back(b[0][i]);
                        ans += b[0][i];
                        sum += b[0][i];
                    }
                    node.erase(node.begin());
                    b.erase(b.begin());
                }
            } else {
                c.push_back(el[0]);
                ans += el[0];
                sum += el[0];
                el.erase(el.begin());
            }
        } else {
            for (long long i = 0; i < b[0].size(); i++){
                c.push_back(b[0][i]);
                ans += b[0][i];
                sum += b[0][i];
            }
            node.erase(node.begin());
            b.erase(b.begin());
        }
        node.push_back(sum);
        b.push_back(c);
    }
    cout << ans;
    return 0;
}
