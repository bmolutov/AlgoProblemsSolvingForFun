#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    vector <bool> used (n + 1);
    used[1] = true;
    queue <int> q;
    q.push (1);
    while (!q.empty ()) {
        int cur = q.front ();
        q.pop ();
        for (auto u: a[cur]) {
            if (!used[u]) {
                used[u] = true;
                q.push (u);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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