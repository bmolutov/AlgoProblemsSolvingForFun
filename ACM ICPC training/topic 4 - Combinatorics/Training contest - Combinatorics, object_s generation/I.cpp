#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Sega {
    vector <long long> tree;
    int size{};
    void init (int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign (2 * size - 1, 0);
    }
    void sett (int i, long long v, int x,  int lx, int rx) {
        if (rx - lx == 1) tree[x] = v;
        else {
            int mx = (lx + rx) >> 1;
            if (i < mx) sett (i, v, 2 * x + 1, lx, mx);
            else sett (i, v, 2 * x + 2, mx, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }
    void sett (int i, long long v) {
        sett (i, v, 0, 0, size);
    }
    long long sum (int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        else if (lx >= l && rx <= r) return tree[x];
        else {
            int mx = (lx + rx) >> 1;
            long long left = sum (l, r, 2 * x + 1, lx, mx);
            long long right = sum (l, r, 2 * x + 2, mx, rx);
            return left + right;
        }
    }
    long long sum (int l, int r) {
        return sum (l, r, 0, 0, size);
    }
};

long long fact[12];

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i <= 11; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int n;
    cin >> n;
    Sega sg;
    sg.init (n + 1);
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sg.sett (i, 1);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (long long) sg.sum (0, a[i]) * fact[n - i];
        sg.sett (a[i], 0);
    }
    cout << ++ans;

    return 0;
}