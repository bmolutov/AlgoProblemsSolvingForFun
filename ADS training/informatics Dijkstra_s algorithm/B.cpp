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

    // for storing the path
    vector <int> p (n + 1, 1);

    while (!q.empty ()) {
        int len = q.top ().first;
        int cur = q.top ().second;
        q.pop ();
        if (len > d[cur]) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int to = i;
            int length = a[cur][i];
            if (d[to] > d[cur] + length && length >= 0) {
                d[to] = d[cur] + length;
                q.push ({d[to], to});

                // for storing the path
                p[to] = cur;
            }
        }
    }
    if (d[f] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        int cur = f;
        vector <int> ans;
        ans.push_back (cur);
        while (cur != s) {
            cur = p[cur];
            ans.push_back (cur);
        }
        for (int i = (int) ans.size () - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
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