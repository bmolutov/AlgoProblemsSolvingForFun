#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int a[N][N];

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v]++;
        if (a[u][v] > 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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