#include <bits/stdc++.h>
using namespace std;

const int inf = 5e7+5;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    bool flag = true;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][k] < inf && a[k][j] < inf) {
                    a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                ans = min (ans, a[i][j]);
            }
            if (i == j && a[i][j] < 0) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << ans;
    } else {
        cout << -1;
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