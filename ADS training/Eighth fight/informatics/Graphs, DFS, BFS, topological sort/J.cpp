#include <bits/stdc++.h>
using namespace std;

int gox[8] = {1, 2, -1, 2, 1, -2, -1, -2};
int goy[8] = {2, 1, 2, -1, -2, 1, -2, -1};

bool isInside (int i, int j, int n) {
    return i >= 1 && i <= n && j >= 1 && j <= n;
}

void solve () {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    queue <pair <int, int>> q;
    q.push ({x1, y1});
    vector <vector <bool>> used (n + 1, vector <bool> (n + 1, false));
    used[x1][y1] = true;
    map <pair <int, int>, pair <int, int>> par;

    while (!q.empty ()) {
        pair <int, int> cur = q.front ();
        q.pop ();
        for (int i = 0; i < 8; i++) {
            int toi = cur.first + gox[i];
            int toj = cur.second + goy[i];
            if (isInside (toi, toj, n) && !used[toi][toj]) {
                q.push ({toi, toj});
                used[toi][toj] = true;
                par[{toi, toj}] = {cur.first, cur.second};
            }
        }
    }
    vector <pair <int, int>> path;
    pair <int, int> cur = {x2, y2};
    while (cur.first != x1 || cur.second != y1) {
        path.emplace_back (cur);
        cur = par[cur];
    }
    path.emplace_back (x1, y1);
    int nn = (int) path.size ();
    cout << nn - 1 << '\n';
    for (int i = nn - 1; i >= 0; i--) {
        cout << path[i].first << ' ' << path[i].second << '\n';
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