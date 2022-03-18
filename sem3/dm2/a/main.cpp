#include <bits/stdc++.h>

using namespace std;

struct task {
    int weight;
    int deadline;
    task(int d, int w) {
        weight = w;
        deadline = d;
    }
};

bool cmp(task a, task b) {
    return (a.weight >= b.weight);
}

int main()
{
    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);
    int n;
    cin >> n;
    vector<task> tasks;
    for (int i = 0; i < n; i++) {
        int d, w;
        cin >> d >> w;
        tasks.push_back(task(d, w));
    }
    sort(tasks.begin(), tasks.end(), cmp);
    set<int> freetime;
    for (int i = 0; i < n; i++) {
        freetime.insert(i);
    }
    long long fine = 0;
    for(int i = 0; i < n; i++) {
        set<int>::iterator place = freetime.lower_bound(tasks[i].deadline);
        if(place == freetime.begin()) {
            fine += tasks[i].weight;
            freetime.erase(--freetime.end());
        } else {
            freetime.erase(--place);
        }
    }
    cout << fine;
    return 0;
}
