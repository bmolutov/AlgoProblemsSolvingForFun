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
    int ans = INT_MAX;
    vector <vector <pair <int, pair <int, int>>>> a (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        a[u].push_back ({v, {c, w}});
        a[v].push_back ({u, {c, w}});
    }

    int s = 1;
    vector <pair <int, int>> d (n + 1, {MAX, MAX});
    d[s].first = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    q.push ({0, s});
    while (!q.empty ()) {
        int len = q.top ().first;
        int v = q.top ().second;
        q.pop ();
        if (len > d[v].first) {
            continue;
        }
        for (auto item: a[v]) {
            int to = item.first;
            int length = item.second.first;
            if (d[to].first > d[v].first + length && length >= 0) {

                d[to].first = d[v].first + length;
//                ans = min (ans, item.second.second);
                d[to].second = item.second.second;

                q.push ({d[to].first, to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i].first << ' ' << d[i].second << '\n';
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