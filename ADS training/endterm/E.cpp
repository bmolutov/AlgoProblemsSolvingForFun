#include <bits/stdc++.h>
using namespace std; // Problem E

const int N = 2e5+5;
vector <bool> alive;
vector <vector <int>> a;
vector <bool> used;
int cnt = 0;

void dfs (int v) {
    used[v] = true;
    for (auto u: a[v]) {
        if (!used[u] && alive[u]) {
            dfs (u);
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    a.resize (n + 1);
    used.assign (n + 1, false);
    alive.assign (n + 1, true);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    for (int i = 1; i <= n; i++) {
        alive[i] = false;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && alive[j]) {
                dfs (j);
                cnt++;
            }
        }
        used.assign (n + 1, false);
        cout << cnt << '\n';
        cnt = 0;
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