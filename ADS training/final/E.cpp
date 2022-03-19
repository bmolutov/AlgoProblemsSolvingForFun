#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> list_, a;
vector <bool> used;
vector <int> temp;
bool checker = true;

void dfs (int v) {
    used[v] = true;
    temp.push_back (v);
    for (auto u: a[v]) {
        if (!used[u]) {
            dfs (u);
        }
    }
}

void solve () {
    int n, t;
    cin >> n >> t;
    a.resize (n + 1);
    used.assign (n + 1, false);
    for (int i = 0; i < t; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs (i);
            list_.push_back (temp);
            if ((int) temp.size () > 3) {
                cout << -1;
                return;
            }
            temp.clear ();
        }
    }

    vector <int> ones;
    vector <pair <int, int>> twos;
    int one = 0, two = 0;
    for (auto i: list_) {
        if ((int) i.size () == 1) {
            one++;
            ones.push_back (i[0]);
        } else if ((int) i.size () == 2) {
            two++;
            twos.push_back ({i[0], i[1]});
        }
    }

//    if (one != 0 && two != 0) {
//        if (one != two) {
//            checker = false;
//        }
//    } else if (one == 0 && two != 0) {
//        checker = false;
//    } else if (one != 0 && two == 0) {
//        if (one % 3 != 0) {
//            checker = false;
//        }
//    }

    if (one > two) {
//        cout << "first\n";
        int i = 0;
        for (i; i < two; i++) {
            list_.push_back ({twos[i].first, twos[i].second, ones[i]});
        }
        if ((one - (i)) % 3 != 0) {
            cout << -1;
            return;
        }
        for (i; i <= one - 3; i += 3) {
            list_.push_back ({ones[i], ones[i + 1], ones[i + 2]});
        }
    } else {
//        cout << "second\n";
        int i = 0;
        for (i; i < one; i++) {
            list_.push_back ({twos[i].first, twos[i].second, ones[i]});
        }
        if (two - i != 0) {
            cout << -1;
            return;
        }
    }
    for (auto i: list_) {
        if ((int) i.size () == 3) {
            for (auto j: i) {
                cout << j << ' ';
                used[j] = true;
            } cout << '\n';
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//    #endif
    solve ();
    return 0;
}