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
    freopen("success.in","r",stdin);
    freopen("success.out","w",stdout);

    int n;
    cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    next_permutation (a.begin (), a.end ());
    for (auto & i: a) {
        cout << i << ' ';
    }

    return 0;
}