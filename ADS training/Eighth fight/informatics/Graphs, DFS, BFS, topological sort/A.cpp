#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int a[N][N];
int b[N];

void solve () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && b[i] != b[j]) {
                cnt++;
            }
        }
    }
    cout << cnt / 2 << '\n';
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