#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> v (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                v[i].push_back (j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (int) v[i].size () << ' ';
        for (auto j: v[i]) {
            cout << j << ' ';
        } cout << '\n';
    }
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