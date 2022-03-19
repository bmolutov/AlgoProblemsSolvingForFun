#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    int ans = INT_MIN, mx = INT_MIN;
    int prev_mx;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mx) {
            prev_mx = mx;
            mx = x;
            if (prev_mx > ans) {
                ans = prev_mx;
            }
        }
        if (x != mx) {
            if (x > ans) {
                ans = x;
            }
        }
    }
    cout << ans;
    return 0;
}