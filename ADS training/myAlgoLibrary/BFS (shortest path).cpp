#include <bits/stdc++.h>
using namespace std;

void solve () {
    /*
     * input example:
        5
        0 1 0 0 1
        1 0 1 0 0
        0 1 0 0 0
        0 0 0 0 0
        1 0 0 0 0
        3 5
     */
    int n;
    cin >> n;
    vector <vector <int>> v (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                v[i].push_back (j);
                v[j].push_back (i);
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
        int cur = q.front ();
        q.pop ();
        for (auto u: v[cur]) {
            if (!used[u]) {
                used[u] = true;
                q.push (u);
                dist[u] = dist[cur] + 1;
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