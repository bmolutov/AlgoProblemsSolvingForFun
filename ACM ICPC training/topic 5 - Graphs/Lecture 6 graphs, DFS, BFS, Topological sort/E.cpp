#include <bits/stdc++.h>
using namespace std;

bool checker = true;

char invert(int c) {
    return c == 1 ? 2 : 1;
}

void dfs (int v, vector <char> & check, vector <vector <int>> & a, int c) {
    check[v] = c;
    for (auto cur: a[v]) {
        if (check[cur] == 0) {
            dfs (cur, check, a, invert (c));
        } else {
            if (check[cur] == c) {
                checker = false;
                return;
            }
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    vector <char> check (n + 1, 0);
    vector <vector <int>> a (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            dfs (i, check, a, c);
        }
    }

    if (checker) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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