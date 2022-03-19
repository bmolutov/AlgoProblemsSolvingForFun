#include <bits/stdc++.h>
using namespace std;

int n, m;

vector <vector <char>> a;
vector <vector <bool>> used;

int goi[4] = {0, 0, -1, 1};
int goj[4] = {1, -1, 0, 0};

bool is_inside (int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void dfs (int i, int j) {
    used[i][j] = true;
    int toi, toj;
    for (int ii = 0; ii < 4; ii++) {
        toi = i + goi[ii];
        toj = j + goj[ii];
        if (is_inside (toi, toj) && !used[toi][toj] && a[toi][toj] == '#') {
            used[toi][toj] = true;
            dfs (toi, toj);
        }
    }
}

void solve () {
    cin >> n >> m;
    a.assign (n + 1, vector <char> (m + 1));
    used.assign (n + 1, vector <bool> (m + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!used[i][j] && a[i][j] == '#') {
                dfs (i, j);
                ans++;
            }
        }
    }
    cout << ans;
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