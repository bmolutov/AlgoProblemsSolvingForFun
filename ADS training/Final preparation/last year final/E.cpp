#include <bits/stdc++.h>
using namespace std; // Problem E

const int inf = INT_MAX;
const int MAX = 2009000999;

void solve () {
    int n;
    cin >> n;
    vector <pair <int, int>> dist (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> dist[i].first >> dist[i].second;
    }

    int s = 1;
    vector <vector <pair <int, int>>> a (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d = abs (dist[i].first - dist[j].first) + abs (dist[i].second - dist[j].second);
            a[i].push_back ({j, d});
            a[j].push_back ({i, d});
        }
    }

    vector <int> d (n + 1, MAX);
//    for (int i = 2; i <= n; i++) {
//        d[i] = abs (dist[1].first - dist[i].first) + abs (dist[1].second - dist[i].second);
//    }
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
//            if (d[to] > d[v] + length && length >= 0) {
//                d[to] = length;
//                q.push ({d[to], to});
//            }
            if (d[to] > max (d[v], length) && length >= 0) {
                d[to] = max (d[v], length);
                q.push ({d[to], to});
            }
//            d[to] = max (d[v], length);
//            q.push ({d[to], to});
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout << d[i] << ' ';
//    } cout << '\n';

    cout << d[n];
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