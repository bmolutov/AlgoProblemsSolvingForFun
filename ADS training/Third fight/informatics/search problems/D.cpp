#include <bits/stdc++.h>
using namespace std;

// error in description of the problem

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n, m, cnt = 0;
    cin >> n >> m;
    int a[n][m];
    int aa[n], bb[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int helper;
    for (int i = 0; i < n; i++) {
        helper = a[i][0];
        for (int j = 1; j < m; j++) {
            if (helper > a[i][j]) {
                helper = a[i][j];
            }
        }
        aa[i] = helper;
    }
    for (int i = 0; i < m; i++) {
        helper = a[0][i];
        for (int j = 1; j < n; j++) {
            if (helper < a[j][i]) {
                helper = a[j][i];
            }
        }
        bb[i] = helper;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (aa[i] == a[i][j] && bb[j] == a[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}