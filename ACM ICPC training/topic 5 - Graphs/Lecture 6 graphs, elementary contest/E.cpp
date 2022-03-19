#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int a[N][N];
int b[N][N];

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v]++;
        b[v][u]++;
    }
    for (int i = 1; i <= n; i++) {
        int cntA = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != 0) {
                cntA++;
            }
        }
        int cntB = 0;
        for (int j = 1; j <= n; j++) {
            if (b[i][j] != 0) {
                cntB++;
            }
        }
        cout << cntB << ' ' << cntA << '\n';
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