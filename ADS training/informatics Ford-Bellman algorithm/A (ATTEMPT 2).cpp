#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, cost;
};

const int inf = 1e9;

void solve () {
    int n, m;
    cin >> n >> m;
    vector <edge> e (m + 1);
    vector <int> d (n + 1, inf);
    d[1] = 0;
    for (int i = 1; i <= m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge temp = {from, to, cost};
        e[i] = temp;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[e[j].from] < inf) {
                d[e[j].to] = min (d[e[j].to], d[e[j].from] + e[j].cost);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == inf) {
            cout << 3000;
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