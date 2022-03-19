#include <bits/stdc++.h>
using namespace std;

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

signed main () {
    fastIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    freopen("inverse.in","r",stdin);
    freopen("inverse.out","w",stdout);

    int n;
    cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}