#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int p[N];

void calc (int n, string s) {
    p[0] = 0;
    int i = 1, j = 0;
    while (i < n) {
        if (s[i] == s[j]) {
            p[i] = j + 1;
            i++; j++;
        } else {
            if (j == 0) {
                p[i] = 0;
                i++;
            } else {
                j = p[j - 1];
            }
        }
    }
}

void kmp (string s, string t, int m, int n) {
    int k = 0, l = 0;
    int pos = -1;
    while (k < m) {
        if (t[l] == s[k]) {
            k++; l++;
            if (l == n) {
                // assigning the position
                pos = k;
            }
        } else if (l == 0) {
            k++;
            if (k == m) {
                // the end of our string
                break;
            }
        } else {
            l = p[l - 1];
        }
    }
    if (pos == -1) {
        cout << -1 << '\n';
    } else {
        cout << m - pos << '\n';
    }
}

void solve () {
    string s, t;
    cin >> s >> t;
    s += s;
    int m = (int) s.size ();
    int n = (int) t.size ();
    calc (n, t);
    kmp (s, t, m, n);
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