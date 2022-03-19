#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int p[N];
int cnt = 0;

void calc (int n, string s) {
    p[0] = 0;
    int i = 1, j = 0;
    while (i < n) {
        if (s[i] == s[j]) {
            p[i] = j + 1;
            i++; j++;
        } else if (j == 0) {
            p[i] = 0;
            i++;
        } else {
            j = p[j - 1];
        }
    }
}

void solve () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        int n = (int) s.size ();
        calc (n, s);
        int at = p[n - 1];
        cout << (int) s.size () + (n - at) * (k - 1) << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    solve ();
    return 0;
}