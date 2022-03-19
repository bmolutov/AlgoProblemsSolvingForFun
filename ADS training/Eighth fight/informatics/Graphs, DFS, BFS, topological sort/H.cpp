#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector <vector <int>> a (N);
vector <char> clr (N, 'w');
bool flag = false;
vector <int> ans;

vector <int> fin;

void dfs (int v) {
    clr[v] = 'g';
    ans.push_back (v);
    for (auto u: a[v]) {
        if (clr[u] == 'g') {
            flag = true;
            return;
        }
        if (clr[u] == 'w') {
            dfs (u);
        }
    }
    clr[v] = 'b';
    fin.push_back (v);
}

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
    }

    for (int i = 1; i <= n; i++) {
        if (clr[i] == 'w') {
            dfs (i);
        }
    }
    if (flag) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        reverse (fin.begin (), fin.end ());
        for (auto &i: fin) {
            cout << i << ' ';
        }
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