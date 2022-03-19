#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, s, f;
    cin >> n >> s >> f;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector <int> d (n + 1, INT_MAX);
    d[s] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    q.push ({0, s});
    while (!q.empty ()) {
        int len = q.top ().first;
        int v = q.top ().second;
        q.pop ();
        if (len > d[v]) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int to = i;
            int length = a[v][i];
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push ({d[to], to});
            }
        }
    }
    if (d[f] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << d[f] << '\n';
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