#include <bits/stdc++.h>
using namespace std; // Problem C

void dfs (int v, vector <vector <int>> & a, vector <bool> & used) {
    used[v] = true;
    for (auto & u: a[v]) {
        if (!used[u]) {
            dfs (u, a, used);
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a (n + 1);
    vector <bool> used (n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs (i, a, used);
            ans++;
        }
    }
    cout << ans - 1;
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