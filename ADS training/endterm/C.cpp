#include <bits/stdc++.h>
using namespace std; // Problem C

vector <vector <int>> a;
vector <char> clr;
int cnt = 0;

void dfs (int v) {
    clr[v] = 1;
    for (auto &u: a[v]) {
        if (clr[u] == 1) {
            cnt++;
        } else if (clr[u] == 0) {
            dfs (u);
        }
    }
    clr[v] = 2;
}

void solve () {
    int n, m;
    cin >> n >> m;
    a.resize (n + 1);
    clr.assign (n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
    }
//    cout << cnt;
//    return;
    dfs (1);
    if (cnt > 1) {
        cout << "NO";
    } else {
        cout << "YES";
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