#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prufer;
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; i++) {
        int a;
        cin >> a;
        prufer.push_back(a);
        degree[a - 1]++;
    }
    int ptr = 0;
    while (ptr < n && degree[ptr] != 1) {
        ptr++;
    }
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int pr = prufer[i] - 1;
        cout << leaf + 1 << ' ' << pr + 1 << endl;
        degree[leaf]--;
        degree[pr]--;
        if (degree[pr] == 1 && pr < ptr) {
            leaf = pr;
        } else {
            ptr++;
            while(ptr < n && degree[ptr] != 1) {
                ptr++;
            }
            leaf = ptr;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (degree[i] == 1) {
            cout << i + 1 << " " << n;
            return 0;
        }
    }
    return 0;
}
