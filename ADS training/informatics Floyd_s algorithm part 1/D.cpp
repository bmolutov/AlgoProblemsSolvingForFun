#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> a;
vector <char> clr;
bool checker = false;

void dfs (int v) {
    clr[v] = 1;
    for (auto &u: a[v]) {
        if (clr[u] == 1) {
            checker = true;
        } else if (clr[u] == 0) {
            dfs (u);
        }
    }
    clr[v] = 2;
}

void solve () {
    int n;
    cin >> n;
    a.resize (n + 1);
    clr.assign (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                a[i].push_back (j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (clr[i] == 0) {
            dfs (i);
        }
    }
    cout << checker;
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