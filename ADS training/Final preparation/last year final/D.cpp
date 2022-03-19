#include <bits/stdc++.h>
using namespace std; // Problem D

void solve () {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    bool flag = false;
    if (s == t) {
        cout << 0;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        s = s.substr ((int) s.size () - 1, 1) + s;
        s.erase ((int) s.size () - 1, 1);
        cnt++;
        if (s == t) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << cnt;
    } else {
        cout << -1;
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