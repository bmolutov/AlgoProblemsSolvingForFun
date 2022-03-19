#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
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

// searching sample in string and printing the entry positions
void kmp (string t, string s, int n, int m) {
    int k = 0, l = 0;
    while (k < m) {
        if (t[l] == s[k]) {
            k++; l++;
            if (l == n) {
                // printing the answer
                // position in string minus length of sample
                cout << k - n << ' ';
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
}

void solve () {
    string s, t;
    cin >> s >> t;
    int m = (int) s.size ();
    int n = (int) t.size ();
    calc (n, t);
    kmp (t, s, n, m);
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