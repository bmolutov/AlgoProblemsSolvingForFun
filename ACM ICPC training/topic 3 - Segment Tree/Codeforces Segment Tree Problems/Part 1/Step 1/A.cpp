#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = (int) 1e5+5;
long long t[4 * N];

void set_ (int i, long long v, int x, int lx, int rx) {
    if (rx - lx == 1) t[x] = v;
    else {
        int m = (lx + rx) >> 1;
        if (i < m) set_ (i, v, 2 * x + 1, lx, m);
        else set_ (i, v, 2 * x + 2, m, rx);
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }
}

long long sum (int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) >> 1;
    long long left = sum (l, r, 2 * x + 1, lx, m);
    long long right = sum (l, r, 2 * x + 2, m, rx);
    return left + right;
}

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        set_ (i, v, 0, 0, n);
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int l, r;
        cin >> l >> r;
        if (q == 1) {
            set_ (l, r, 0, 0, n);
        } else {
            cout << sum (l, r, 0, 0, n) << '\n';
        }
    }

    return 0;
}