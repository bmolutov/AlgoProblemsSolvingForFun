#include <bits/stdc++.h>
using namespace std; // Problem F

void solve () {
    int n;
    cin >> n;
    vector <long long> a (n);
    vector <long long> c (n + 1);
    c[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i + 1] = c[i] + a[i];
    }
    sort (c.begin (), c.end ());
    long long ans = INT_MAX;
    for (int i = 0; i < n + 1; i++) {
        ans = min (ans, abs (c[i] - c[i + 1]));
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve ();
    return 0;
}