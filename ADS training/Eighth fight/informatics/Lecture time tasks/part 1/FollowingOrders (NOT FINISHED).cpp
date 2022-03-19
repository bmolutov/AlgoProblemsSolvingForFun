#include <bits/stdc++.h>
using namespace std;

const int N = 300;
vector <vector <char>> a (N);
vector <bool> used (N, false);
vector <char> ans;

void dfs (char v) {
    used[v] = true;
    for (auto u: a[v]) {
        if (!used[u]) {
            dfs (u);
        }
    }
    ans.push_back (v);
}

void solve () {
    string s1, s2;
    while (getline (cin, s1) && getline (cin, s2)) {
        vector <char> v;
        for (auto i: s1) {
            if (i != ' ') {
                v.push_back (i);
            }
        }
        for (int i = 0; i < (int) s2.size () - 1; i += 2) {
            char p = s2[i], k = s2[i + 1];
            a[p].push_back (k);
        }
        for (auto j: v) {
            dfs (j); // begin
            for (auto i: v) {
                if (!used[i] && i != j) {
                    dfs (i);
                }
            }
            for (auto i: ans) {
                cout << i;
            } cout << '\n';
            ans.clear ();
            used.assign (N, false);
        }
        a.assign (N, {});
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