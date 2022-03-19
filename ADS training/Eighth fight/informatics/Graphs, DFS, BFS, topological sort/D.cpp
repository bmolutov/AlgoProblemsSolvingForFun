#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector <int> temp;
vector <vector <int>> a (N);
vector <bool> used (N, false);

void dfs (int v) {
    used[v] = true;
    temp.push_back (v);
    for (auto &u: a[v]) {
        if (!used[u]) {
            dfs (u);
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    vector <vector <int>> ans;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs (i);
            ans.push_back (temp);
            temp.clear ();
        }
    }
    cout << (int) ans.size () << '\n';
    for (auto &i: ans) {
        cout << (int) i.size () << '\n';
        for (auto &j: i) {
            cout << j << ' ';
        } cout << '\n';
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