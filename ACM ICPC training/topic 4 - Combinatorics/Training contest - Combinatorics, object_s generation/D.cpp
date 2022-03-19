#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    freopen("choose.in","r",stdin);
    freopen("choose.out","w",stdout);

    int n, k;
    cin >> n >> k;

    vector <int> v (n);
    for (int i = 0; i < k; i++) {
        v[i] = 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                cout << i + 1 << ' ';
            }
        } cout << '\n';
    } while (prev_permutation (v.begin (), v.end ()));

    return 0;
}