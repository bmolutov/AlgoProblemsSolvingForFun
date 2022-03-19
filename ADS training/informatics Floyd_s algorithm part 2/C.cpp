#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                a[i][j] = inf;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][k] < inf && a[k][j] < inf) {
                    a[i][j] = min (a[i][j], max (-inf, a[i][k] + a[k][j]));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][k] < inf && a[k][j] < inf && a[k][k] < 0) {
                    a[i][j] = -inf;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == -inf) {
                cout << 2;
            } else if (i == j) {
                cout << 1;
            } else if (a[i][j] == inf) {
                cout << 0;
            } else {
                cout << 1;
            } cout << ' ';
        } cout << '\n';
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