#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
int p[N];

int calc_max (int n, string s) {
    int i = 1, j = 0;

    int mx = 0;

    while (i < n) {
        if (s[i] == s[j]) {
            p[i] = j + 1;

            mx = max (p[i], mx);

            i++; j++;
        } else if (j == 0) {
            p[i] = 0;
            i++;
        } else {
            j = p[j - 1];
        }
    }
    return mx;
}

void solve () {
    string s;
    cin >> s;
    int n = (int) s.size ();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m = (int) s.size ();
        ans += m - calc_max (m, s);
        s.erase (s.begin ());
    }
    cout << ans << '\n';
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