#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector <vector <int>> a (N);
bool used[N];
vector <int> temp;

void dfs (int v) {
    temp.push_back (v);
    used[v] = true;
    for (auto u: a[v]) {
        if (!used[u]) {
            dfs (u);
            temp.push_back (v);
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        a[u].push_back (v);
        a[v].push_back (u);
    }
    dfs (1);
    vector <pair <int, int>> ans;
    for (int i = 0; i < (int) temp.size () - 1; i++) {
        for (auto & edge : edges) {
            if (temp[i] == edge.first && temp[i + 1] == edge.second) {
                cout << temp[i] << ' ' << temp[i + 1] << '\n';
            }
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