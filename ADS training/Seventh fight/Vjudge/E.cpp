#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int p[N];

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
    while (true) {
        string s;
        cin >> s;
        if (s == ".") {
            return;
        }
        int n = (int) s.size ();
        calc (n, s);
        int temp = n - p[n - 1];
        if (n % temp == 0) {
            cout << n / temp << '\n';
        } else {
            cout << 1 << '\n';
        }
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