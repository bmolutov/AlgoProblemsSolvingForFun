#include <bits/stdc++.h>
using namespace std;

const int N = 51;
vector <vector <int>> a (N);
vector <char> clr (N, 'w');
bool flag = false;

void dfs (int v) {
    clr[v] = 'g';
    for (auto u: a[v]) {
        if (clr[u] == 'g') {
            flag = true;
            return;
        }
        if (clr[u] == 'w') {
            dfs (u);
        }
    }
    clr[v] = 'b';
}

void solve () {
    int n;
    cin >> n;
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
        if (clr[i] == 'w') {
            dfs (i);
        }
    }
    cout << flag << '\n';
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