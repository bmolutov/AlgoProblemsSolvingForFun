#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    int s, f;
    cin >> s >> f;
    vector <vector <int>> a (n + 1);
    vector <int> par (n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    vector <bool> used (n + 1);
    used[s] = true;
    queue <int> q;
    q.push (s);
    while (!q.empty ()) {
        int cur = q.front ();
        q.pop ();
        for (auto u: a[cur]) {
            if (!used[u]) {
                used[u] = true;
                q.push (u);
                par[u] = cur;
            }
        }
    }
    vector <int> path;
    int cur = f;
    while (cur != s) {
        if (cur == -1) {
            cout << -1;
            return;
        }
        path.push_back (cur);
        cur = par[cur];
    }
    path.push_back (s);
    cout << (int) path.size () - 1 << '\n';
    for (int i = (int) path.size () - 1; i >= 0; i--) {
        cout << path[i] << ' ';
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