#include <bits/stdc++.h>
using namespace std;

int goLeft (int n) {
    return (n % 1000) * 10 + (n / 1000);
}

int goRight (int n) {
    return (n % 10) * 1000 + (n / 10);
}

bool firstOk (int n) {
    return (n / 1000) != 9;
}

bool lastOk (int n) {
    return (n % 10) != 1;
}

int incFirst (int n) {
    return (n + 1000);
}

int decLast (int n) {
    return (n - 1);
}

const int N = 1e4;

void solve () {
    vector <int> par (N, -1);
    int s, f;
    cin >> s >> f;
    queue <int> q;

    q.push (s);

    while (!q.empty ()) {
        int cur = q.front ();
        q.pop ();
        vector <int> med;
        if (firstOk (cur)) {
            med.push_back (incFirst (cur));
        } else {
            med.push_back (cur);
        }
        if (lastOk (cur)) {
            med.push_back (decLast (cur));
        } else {
            med.push_back (cur);
        }
        med.push_back (goLeft (cur));
        med.push_back (goRight (cur));

        for (auto i: med) {
            if (par[i] == -1){
                par[i] = cur;
                q.push (i);
            }
        }
    }
    vector <int> path;
    int cur = f;
    while (cur != s) {
        path.push_back (cur);
        cur = par[cur];
    }
    path.push_back (s);
    for (int i = (int) path.size () - 1; i >= 0; i--) {
        cout << path[i] << '\n';
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