#include <bits/stdc++.h>
using namespace std;

const int N = 101;

vector <vector <int>> a (N);
vector <int> ans;
vector <bool> used (N, false);

void dfs (int v) {
    used[v] = true;
    for (auto u: a[v]) {
        if (!used[u]) {
            dfs (u);
        }
    }
    ans.push_back (v);
}

void solve () {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back (v);
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs (i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        } cout << '\n';

        a.assign (N, {});
        used.assign (N, false);
        ans.clear ();
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