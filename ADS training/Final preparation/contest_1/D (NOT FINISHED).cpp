#include <bits/stdc++.h>
using namespace std;

int sq (int x1, int y1, int x2, int y2) {
    double temp = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    temp = temp / sqrt (2);

    int ans;
    if (temp > floor (temp)) {
        ans = (int) temp + 1;
        return ans;
    } else {
        ans = (int) temp;
        return ans;
    }
}

void solve () {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = sq (x1, y1, x2, y2);
    }
    sort (a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
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