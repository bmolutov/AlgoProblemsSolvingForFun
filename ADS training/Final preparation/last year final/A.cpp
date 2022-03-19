#include <bits/stdc++.h>
using namespace std; // Problem A

void solve () {
    string s;
    cin >> s;
    vector <char> temp;
    for (char & i : s) {
        if ((int) temp.size () == 0 || temp.back () != i) {
            temp.push_back (i);
        } else {
            temp.pop_back ();
        }
    }
    if (temp.empty ()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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