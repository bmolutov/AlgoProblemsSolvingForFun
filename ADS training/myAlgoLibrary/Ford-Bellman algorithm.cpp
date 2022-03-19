#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve () {
    int n, m;
    cin >> n >> m;
    int e[m][3];
    vector <int> d (n, inf);
    d[0] = 0;
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--;
        e[i][1]--;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (d[e[j][0]] < inf) {
                d[e[j][1]] = min (d[e[j][1]], d[e[j][0]] + e[j][2]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
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