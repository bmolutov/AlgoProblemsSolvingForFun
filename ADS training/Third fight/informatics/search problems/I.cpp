#include <bits/stdc++.h>
using namespace std;

void solve (int a[], int n, int x) {
    int l, r, left, right;
    // left bound
    l = -1, r = n;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    left = r;
    // right bound
    l = -1, r = n;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    right = l;
    if (a[left] != x || a[right] != x) {
        cout << 0 << '\n';
    }
    else {
        cout << ++left << ' ' << ++right << '\n';
    }
}

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        solve (a, n, x);
    }
    return 0;
}