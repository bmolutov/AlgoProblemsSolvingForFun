#include <bits/stdc++.h>
using namespace std; // Problem B

const int N = 1e4+5;
const int inf = INT_MAX;

bool check (int n) {
    return n >= 1 && n <= (2 * N);
}

void solve () {
    int s, f;
    cin >> s >> f;
    if (s == f) {
        cout << 0;
        return;
    }

    vector <bool> used (10 * N, false);
    used[s] = true;
    queue <int> q;
    q.push (s);
    vector <int> dist (10 * N, inf);
    dist[s] = 0;
    vector <int> par (10 * N, -1);

    while (!q.empty ()) {
        int v = q.front ();
        q.pop ();
        if (check (v - 1) && !used[v - 1]) {
            used[v - 1] = true;
            q.push (v - 1);
            dist[v - 1] = dist[v] + 1;
            par[v - 1] = v;
        }
        if (check (2 * v) && !used[2 * v]) {
            used[2 * v] = true;
            q.push (2 * v);
            dist[2 * v] = dist[v] + 1;
            par[2 * v] = v;
        }
        if (dist[f] != inf) {
            break;
        }
    }
    vector <int> ans = {f};
    int cur = f;
    while (par[cur] != s) {
        cur = par[cur];
        ans.push_back (cur);
    }
    cout << (int) ans.size () << '\n';
    for (int i = (int) ans.size () - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
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