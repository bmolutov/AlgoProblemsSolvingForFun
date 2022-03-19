#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> src (n + 1), sink (n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                src[i].push_back (j);
                sink[j].push_back (i);
            }
        }
    }
    vector <int> a, b;
    for (int i = 1; i <= n; i++) {
        if ((int) src[i].size () != 0 && (int) sink[i].size () == 0) {
            a.push_back (i);
        }
        if ((int) sink[i].size () != 0 && (int) src[i].size () == 0) {
            b.push_back (i);
        }
        if ((int) src[i].size () == 0 && (int) sink[i].size () == 0) {
            a.push_back (i);
            b.push_back (i);
        }
    }
    cout << (int) a.size () << ' ';
    for (auto i: a) {
        cout << i << ' ';
    } cout << '\n';
    cout << (int) b.size () << ' ';
    for (auto i: b) {
        cout << i << ' ';
    } cout << '\n';
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