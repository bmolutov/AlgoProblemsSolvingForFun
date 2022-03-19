#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

const int p = 31;
const unsigned long long mod = ULLONG_MAX;

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    string s, sub;
    cin >> s >> sub;

    int n = (int) s.size (), m = (int) sub.size ();
    int mx = max (n, m);
    unsigned long long factors[mx];
    factors[0] = 1;
    for (int i = 1; i < mx; i++) {
        factors[i] = factors[i - 1] * p;
        factors[i] %= mod;
    }

    unsigned long long s_hash[n];
    for (int i = 0; i < n; i++) {
        s_hash[i] = (s[i] - 'a' + 1) * factors[i];
        s_hash[i] %= mod;
        if (i > 0) {
            s_hash[i] += s_hash[i - 1];
            s_hash[i] %= mod;
        }
    }

    unsigned long long sub_hash = 0;
    for (int i = 0; i < m; i++) {
        sub_hash += (sub[i] - 'a' + 1) * factors[i];
        sub_hash %= mod;
    }

    for (int i = 0; i + m - 1 < n; i++) {
        unsigned long long cur = s_hash[i + m - 1];
        if (i > 0) {
            cur -= s_hash[i - 1];
        }
        if (cur == sub_hash * factors[i]) {
            cout << i << ' ';
        }
    }

    return 0;
}