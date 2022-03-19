#include <bits/stdc++.h>
using namespace std; // Problem F

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));
    vector <vector <int>> aa (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> aa[i][j];
        }
    }
    a = aa;
    vector <bool> used (n + 1, false);
    for (int t = 1; t <= n; t++) {
        int v;
        cin >> v;
        used[v] = true;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (used[k] && used[i] && used[j]) {
                        a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
                    }
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (used[i] && used[j]) {
                    mx = max (mx, a[i][j]);
                }
            }
        }
        cout << mx << '\n';
        a = aa;
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