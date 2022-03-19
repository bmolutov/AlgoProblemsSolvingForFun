#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n; cin >> n;
    int a[n], min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            a[i] = min;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}