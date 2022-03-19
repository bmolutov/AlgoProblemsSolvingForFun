#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    vector <pair <int, pair <int, int>>> g (m);
    // input
    for (int i = 0; i < m; i++) {
        cin >> g[i].second.first >> g[i].second.second >> g[i].first;
    }
    int cost = 0;
//    vector <pair <int, int>> res;
    sort (g.begin (), g.end ());
    vector <int> tree_id (n);
    for (int i = 0; i < n; i++) {
        tree_id[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (tree_id[a] != tree_id[b]) {
            cost += l;
//            res.emplace_back(a, b);
            int old_id = tree_id[b], new_id = tree_id[a];
            for (int j = 0; j < n; j++) {
                if (tree_id[j] == old_id) {
                    tree_id[j] = new_id;
                }
            }
        }
    }
    cout << cost;
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