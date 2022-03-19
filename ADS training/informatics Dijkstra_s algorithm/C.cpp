#include <bits/stdc++.h>
using namespace std;

const int MAX = INT_MAX;

void solve () {
    int n;
    cin >> n;
    vector <int> cost (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    int m; cin >> m;
    vector <vector <int>> a (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }

    int s = 1;
    vector <int> d (n + 1, MAX);
    d[s] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    q.push ({0, s});

    while (!q.empty ()) {
        int len = q.top ().first;
        int v = q.top ().second;
        q.pop ();
        if (len > d[v]) {
            continue;
        }
        for (int i = 0; i < (int) a[v].size (); i++) {
            int to = a[v][i];
            int length = cost[v];
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push ({d[to], to});
            }
        }
    }
    if (d[n] == MAX) {
        cout << -1;
    } else {
        cout << d[n];
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