#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Sega {
    vector <int> tree;
    int size{};

    void init (int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign (2 * size - 1, 0);
    }

    void sett (int i, int x, int lx, int rx) {
        if (rx - lx == 1) tree[x] = 1;
        else {
            int mx = (lx + rx) >> 1;
            if (i < mx) sett (i, 2 * x + 1, lx, mx);
            else sett (i, 2 * x + 2, mx, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }
    void sett (int i) {
        sett (i, 0, 0, size);
    }

    int sum (int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        else if (lx >= l && rx <= r) return tree[x];
        else {
            int mx = (lx + rx) >> 1;
            int left = sum (l, r, 2 * x + 1, lx, mx);
            int right = sum (l, r, 2 * x + 2, mx, rx);
            return left + right;
        }
    }
    int sum (int l, int r) {
        return sum (l, r, 0, 0, size);
    }
};

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    Sega sg;
    sg.init (n + 1);
    vector <pair <int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sg.sett (x);
        int sum = sg.sum (x + 1, n + 1);

        a.emplace_back(x, sum);
    }
    for (auto & i: a) {
        cout << i.second << ' ';
    }

    return 0;
}