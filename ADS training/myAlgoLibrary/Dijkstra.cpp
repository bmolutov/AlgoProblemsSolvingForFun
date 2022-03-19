#include <bits/stdc++.h>
using namespace std;

const int MAX = 2009000999;

void solve () {
    /*
    this algorithm is used for searching distances
    from the starting vertex to others
    */
    int n, m;
    cin >> n >> m;
    int s; // starting vertex
    cin >> s;
    s++;
    vector <vector <pair <int, int>>> a (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u++; v++;
        a[u].push_back ({v, c});
        a[v].push_back ({u, c});
    }

    vector <int> d (n + 1, MAX);
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
        for (auto item: a[v]) {
            int to = item.first;
            int length = item.second;
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push ({d[to], to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    } cout << '\n';
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