#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> a (n + 1);
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
    int s, f;
    cin >> s >> f;
    vector <bool> used (n + 1);
    used[s] = true;
    vector <int> dist (n + 1, -1);
    dist[s] = 0;
    queue <int> q;
    q.push (s);
    while (!q.empty ()) {
        int v = q.front ();
        q.pop ();
        for (auto u: a[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push (u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    cout << dist[f] << '\n';
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