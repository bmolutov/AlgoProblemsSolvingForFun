#include <bits/stdc++.h>
using namespace std;

string solve (int a[], int x, int l, int r) {
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) {
            l = m;
        }
        else if (a[m] > x) {
            r = m;
        }
        else {
            return "YES\n";
        }
    }
    return "NO\n";
}

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cout << solve (a, x, -1, n);
    }
    return 0;
}