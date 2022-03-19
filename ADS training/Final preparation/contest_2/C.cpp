#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector <char> v, c;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            v.push_back (s[i]);
        } else {
            c.push_back (s[i]);
        }
    }
    sort (v.begin (), v.end ());
    sort (c.begin (), c.end ());
    for (auto k: v) cout << k;
    for (auto k: c) cout << k;
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