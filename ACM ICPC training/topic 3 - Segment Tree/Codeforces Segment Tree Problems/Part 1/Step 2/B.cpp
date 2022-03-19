#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = 1e5+5;

int t[4 * N];

void set_ (int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
    } else {
        int mx = (lx + rx) >> 1;
        if (i < mx) set_ (i, v, 2 * x + 1, lx, mx);
        else set_ (i, v, 2 * x + 2, mx, rx);
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }
}

int find (int k, int x, int lx, int rx) {
    if (rx - lx == 1) {
        return lx;
    } else {
        int mx = (lx + rx) >> 1;
        if (k < t[2 * x + 1]) return find (k, 2 * x + 1, lx, mx);
        else return find (k - t[2 * x + 1], 2 * x + 2, mx, rx);
    }
}

int a[N];

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = v;
        set_ (i, v, 0, 0, n);
    }
    for (int i = 0; i < m; i++) {
        int q, k;
        cin >> q >> k;
        if (q == 1) {
            a[k] = 1 - a[k];
            set_ (k, a[k], 0, 0, n);
        } else {
            cout << find (k, 0, 0, n) << '\n';
        }
    }

    return 0;
}