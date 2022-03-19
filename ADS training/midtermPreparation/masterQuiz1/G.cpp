#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxN = 100'005;
const int LOG = 17;
int a[maxN];
int m[maxN][LOG];

int query (int l, int r) {
    int length = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) <= length) {
        k++;
    }
    return min (m[l][k], m[r - (1 << k) + 1][k]);
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min (m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        ans += query (l, r);
    }
    cout << ans;

    return 0;
}