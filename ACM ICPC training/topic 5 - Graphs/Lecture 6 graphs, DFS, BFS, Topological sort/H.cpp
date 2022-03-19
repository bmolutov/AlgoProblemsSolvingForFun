#include <bits/stdc++.h>
using namespace std;

int tox[] = {-1, 0, 0, 1};
int toy[] = {0, -1, 1, 0};

bool check (int toi, int toj, int n, int m) {
    return (toi >= 1 && toi <= n && toj >= 1 && toj <= m);
}

void solve () {
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        int n, m;
        cin >> m >> n;
        pair <int, int> s;
        vector <vector <char>> a (n + 1, vector <char> (m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '@') {
                    s = {i, j};
                }
            }
        }
        vector <vector <bool>> used (n + 1, vector <bool> (m + 1, false));
        used[s.first][s.second] = true;
        queue <pair <int, int>> q;
        q.push (s);
        int cnt = 1;
        while (!q.empty ()) {
            auto cur = q.front ();
            q.pop ();
            for (int i = 0; i < 4; i++) {
                pair <int, int> temp = {tox[i] + cur.first, toy[i] + cur.second};
                if (check (temp.first, temp.second, n, m) && !used[temp.first][temp.second] && a[temp.first][temp.second] != '#') {
                    used[temp.first][temp.second] = true;
                    q.push (temp);
                    cnt++;
                }
            }
        }
        cout << "Case " << ii << ": " << cnt << '\n';
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