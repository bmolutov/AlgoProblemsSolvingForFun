#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;

    vector <vector <int>> a (n + 1);
    vector <int> par (n + 1, -1);
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
    queue <int> q;
    q.push (s);
    while (!q.empty ()) {
        int cur = q.front ();
        q.pop ();
        for (auto u: a[cur]) {
            if (!used[u]) {
                used[u] = true;
                q.push (u);
                par[u] = cur;
            }
        }
    }
    vector <int> path;
    int cur = f;
    while (cur != s) {
        if (cur == -1) {
            cout << -1;
            return;
        }
        path.push_back (cur);
        cur = par[cur];
    }
    path.push_back (s);

    if ((int) path.size () - 1 == 0) {
        cout << 0;
        return;
    }

    cout << (int) path.size () - 1 << '\n';
    for (int i = (int) path.size () - 1; i >= 0; i--) {
        cout << path[i] << ' ';
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