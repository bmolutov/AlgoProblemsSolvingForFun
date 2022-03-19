#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             cin >> a[i][j];
        }
    }
    int mn = INT_MAX;
    int x, y, z;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int temp = a[i][j] + a[j][k] + a[i][k];
                if (temp < mn) {
                    x = i, y = j, z = k;
                    mn = temp;
                }
            }
        }
    }
    cout << ++x << ' ' << ++y << ' ' << ++z;
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