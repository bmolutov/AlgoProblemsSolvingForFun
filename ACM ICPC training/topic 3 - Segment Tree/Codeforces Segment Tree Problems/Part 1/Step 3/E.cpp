#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Sega {
    vector <long long> tree;
    int size;
    void init (int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign (2 * size - 1, 0);
    }
    void add (int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        } else if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        } else {
            int m = (lx + rx) >> 1;
            add (l, r, v, 2 * x + 1, lx, m);
            add (l, r, v, 2 * x + 2, m, rx);
        }
    }
    void add (int l, int r, int v) {
        add (l, r, v, 0, 0, size);
    }
    long long get (int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return tree[x];
        } else {
            int m = (lx + rx) >> 1;
            if (i < m) return get (i, 2 * x + 1, lx, m) + tree[x];
            else return get (i, 2 * x + 2, m, rx) + tree[x];
        }
    }
    long long get (int i) {
        return get (i, 0, 0, size);
    }
};

signed main () {
    fastIO();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Sega sg;
    int n, m;
    cin >> n >> m;
    sg.init (n);

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            sg.add (l, r, v);
        } else {
            int ii;
            cin >> ii;
            cout << sg.get (ii) << '\n';
        }
    }

    return 0;
}