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

void solve () {
    string s;
    cin >> s;
    int n = (int) s.size ();
    calc (n, s);
//    for (int i = 0; i < n; i++) {
//        cout << p[i] << ' ';
//    }
    int pos = n - 1;
    while (p[pos] == 0) {
        pos--;
    } pos++;

    vector <int> ans = {pos - p[pos - 1]};
    for (int i = ans[0] + 1; i <= pos / 2; i++) {
        if (pos % i == 0) {
            ans.push_back (i);
//            cout << i << '\n';
        }
    }
//    for (auto & i: ans) {
//        cout << i << ' ';
//    }
    cout << (int) ans.size ();
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