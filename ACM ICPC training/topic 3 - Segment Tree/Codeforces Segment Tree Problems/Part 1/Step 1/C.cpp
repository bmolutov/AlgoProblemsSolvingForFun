#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = 1e5+5;

struct Node {
    int min, cnt;
};

Node t[4 * N]{};

struct Sega {
    static Node combine (Node a, Node b) {
        if (a.min < b.min) {
            return a;
        } else if (b.min < a.min) {
            return b;
        } else {
            return {a.min, a.cnt + b.cnt};
        }
    }

    const Node ZERO = {INT_MAX, 0};

    void set_ (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {v, 1};
        } else {
            int mx = (lx + rx) >> 1;
            if (i < mx) set_ (i, v, 2 * x + 1, lx, mx);
            else set_ (i, v, 2 * x + 2, mx, rx);
            t[x] = combine (t[2 * x + 1], t[2 * x + 2]);
        }
    }

    Node calc (int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return ZERO;
        } else if (lx >= l && rx <= r) {
            return t[x];
        } else {
            int mx = (lx + rx) >> 1;
            Node left = calc (l, r, 2 * x + 1, lx, mx);
            Node right = calc (l, r, 2 * x + 2, mx, rx);
            return combine (left, right);
        }
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
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        sg.set_ (i, v, 0, 0, n);
    }
    for (int i = 0; i < m; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            sg.set_ (l, r, 0, 0, n);
        } else {
            cout << sg.calc (l, r, 0, 0, n).min << ' ';
            cout << sg.calc (l, r, 0, 0, n).cnt << '\n';
        }
    }

    return 0;
}