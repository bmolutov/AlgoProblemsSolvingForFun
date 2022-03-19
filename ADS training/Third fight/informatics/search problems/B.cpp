#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n; cin >> n; int a[n], max = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }
    cout << max;
    return 0;
}