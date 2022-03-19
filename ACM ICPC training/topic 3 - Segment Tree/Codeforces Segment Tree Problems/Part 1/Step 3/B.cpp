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

    void sett (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) tree[x] = v;
        else {
            int mx = (lx + rx) >> 1;
            if (i < mx) sett (i, v, 2 * x + 1, lx, mx);
            else sett (i, v, 2 * x + 2, mx, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void sett (int i, int v) {
        sett (i, v, 0, 0, size);
    }

    int find (int k, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return lx;
        }
        else {
            int mx = (lx + rx) >> 1;
            if (k < tree[2 * x + 2]) return find (k, 2 * x + 2, mx, rx);
            else return find (k - tree[2 * x + 2], 2 * x + 1, lx, mx);
        }
    }

    int find (int k) {
        return find (k, 0, 0, size);
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
    for (int i = 1; i <= n; i++) sg.sett (i, 1);

    vector <pair <int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x, 0);
    }

    for (int i = n - 1; i >= 0; i--) {
        int k = a[i].first;
        int ans = sg.find (k);

        sg.sett (ans, 0);

        a[i].second = ans;
    }
    for (auto & i: a) {
        cout << i.second << ' ';
    }

    return 0;
}