#include <bits/stdc++.h>
using namespace std; // Problem D

void solve () {
    int n, m;
    cin >> n >> m;
    vector <vector <bool>> a (n + 1, vector <bool> (n + 1, false));
    vector <vector <bool>> b (n + 1, vector <bool> (n + 1, false));
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
//        if (u > v) swap (u, v);
        a[u][v] = true;
        a[v][u] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && !a[i][j] && !a[j][i]) { // ???
                b[i][j] = true;
                b[j][i] = true;
            }
        }
    }

    vector <vector <int>> aa (n + 1), bb (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                aa[i].push_back (j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i][j]) {
                bb[i].push_back (j);
            }
        }
    }

    vector <bool> used1 (n + 1);
    used1[1] = true;
    vector <int> dist1 (n + 1, -1);
    dist1[1] = 0;
    queue <int> q1;
    q1.push (1);
    while (!q1.empty ()) {
        int cur = q1.front ();
        q1.pop ();
        for (auto u: aa[cur]) {
            if (!used1[u]) {
                used1[u] = true;
                q1.push (u);
                dist1[u] = dist1[cur] + 1;
            }
        }
    }
    int ans1 = dist1[n];
    if (ans1 == -1) {
        cout << -1;
        return;
    }

    vector <bool> used2 (n + 1);
    used2[1] = true;
    vector <int> dist2 (n + 1, -1);
    dist2[1] = 0;
    queue <int> q2;
    q2.push (1);
    while (!q2.empty ()) {
        int cur = q2.front ();
        q2.pop ();
        for (auto u: bb[cur]) {
            if (!used2[u]) {
                used2[u] = true;
                q2.push (u);
                dist2[u] = dist2[cur] + 1;
            }
        }
    }
    int ans2 = dist2[n];
    if (ans2 == -1) {
        cout << -1;
        return;
    }

    cout << max (ans1, ans2);
//    cout << ans1 << ' ' << ans2;
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