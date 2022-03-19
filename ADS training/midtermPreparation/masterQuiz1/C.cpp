#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int len = 1000000;
int a[len];

int bs (int a[], int x, int n) {
    int l = -1, r = n;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int size = 0;
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        a[size++] = x;
        int temp = x - 3000;
        if (temp < 0) {
            temp = 0;
        }
        int ind = bs (a, temp, size);
        cout << size - ind << endl;
    }

    return 0;
}