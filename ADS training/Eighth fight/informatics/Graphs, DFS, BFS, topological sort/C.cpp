#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs (int v, vector <vector <int>>& a, vector <bool>& used) {
    used[v] = true;
    ans++;
    for (auto u: a[v]) {
        if (!used[u]) {
            dfs (u, a, used);
        }
    }
}

void solve () {
    int n, s;
    cin >> n >> s;
    vector <vector <int>> a (n + 1);
    vector <bool> used (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                a[i].push_back (j);
                a[j].push_back (i);
            }
        }
    }
    dfs (s, a, used);
    cout << ans;
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