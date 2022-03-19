#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = 1e5+5;

int t[4 * N];

void set_ (int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) t[x] = v;
    else {
        int mx = (lx + rx) >> 1;
        if (i < mx) set_ (i, v, 2 * x + 1, lx, mx);
        else set_ (i, v, 2 * x + 2, mx, rx);
        t[x] = max (t[2 * x + 1], t[2 * x + 2]);
    }
}

int first_above (int v, int x, int lx, int rx) {
    if (t[x] < v) return -1;
    else if (rx - lx == 1) return lx;
    else {
        int mx = (lx + rx) >> 1;
        int res = first_above (v, 2 * x + 1, lx, mx);
        if (res == -1) res = first_above (v, 2 * x + 2, mx, rx);
        return res;
    }
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
        int v;
        cin >> v;
        set_ (i, v, 0, 0, n);
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int ii, v;
            cin >> ii >> v;
            set_ (ii, v, 0, 0, n);
        } else {
            int x;
            cin >> x;
            cout << first_above (x, 0, 0, n) << '\n';
        }
    }

    return 0;
}