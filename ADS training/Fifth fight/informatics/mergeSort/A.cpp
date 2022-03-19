#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

long long square (long long x) {
    return x * x;
}

long long cube (long long x) {
    return x * x * x;
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int x;
    cin >> x;
    int i = 1, j = 1;
    long long cur = 1;
    for (int t = 0; t < x; t++) {
        if (square (i) < cube (j)) {
            cur = square (i);
            i++;
        } else if (cube (j) < square (i)) {
            cur = cube (j);
            j++;
        } else {
            cur = square (i);
            i++;
            j++;
        }
    }
    cout << cur;

    return 0;
}