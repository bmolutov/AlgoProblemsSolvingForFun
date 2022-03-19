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
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);

    int n;
    cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        } cout << '\n';
    } while (next_permutation (a.begin (), a.end ()));

    return 0;
}