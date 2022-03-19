#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve () {
    int n, m;
    cin >> n >> m;
    vector <int> d (n + 1, inf);
    d[1] = 0;
    map <pair <int, int>, int> e;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (from == to) {
            continue;
        }
        if (e[{from, to}] == 0) {
            e[{from, to}] = cost;
        } else {
            e[{from, to}] = min (e[{from, to}], cost);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto j: e) {
            if (d[j.first.first] < inf) {
                d[j.first.second] = min (d[j.first.second], d[j.first.first] + j.second);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == inf) {
            cout << 30000;
        } else {
            cout << d[i];
        } cout << ' ';
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve ();
    return 0;
}