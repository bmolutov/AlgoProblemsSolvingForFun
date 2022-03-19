#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bs (int a[], int l, int r, int x) {
    if (r >= l) {
        int m = l + (r - l) / 2;
        if (a[m] == x) {
            return m;
        }
        if (a[m] > x) {
            return bs (a, l, m - 1, x);
        }
        if (a[m] < x) {
            return bs (a, m + 1, r, x);
        }
    }
    return -1;
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int t;
    cin >> t;
    int q[t];
    for (int i = 0; i < t; i++) {
        cin >> q[i];
    }
    int n, m;
    cin >> n >> m;
    int temp[n * m];
    int p = 0;

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        int trial[m];
        for (int j = 0; j < m; j++) {
            cin >> trial[j];
            arr[i][j] = trial[j];
        }
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                temp[p++] = trial[j];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                temp[p++] = trial[j];
            }
        }
    }
    int ii = 0, jj = n * m - 1;
    while (ii < jj) {
        swap (temp[ii], temp[jj]);
        ii++; jj--;
    }
//    for (int i = 0; i < n * m; i++) {
//        cout << temp[i] << ' ';
//    }
//    return 0;

//    for (int i = 0; i < t; i++) {
//        int ind = bs (temp, n * m, q[i]);
//        if (ind != -1) {
//            int pos = n * m - ind; // 4
//            int x = pos / m; // 4 / m
//            int y;
//            if (x % 2 == 1) {
//                y = m - (pos % m);
//            } else {
//                y = pos % m;
//            }
//            cout << x << ' ' << y << endl;
//        } else {
//            cout << -1;
//        }
//    }

    for (int I = 0; I < t; I++) {
        int ind = bs (temp, 0, n * m - 1, q[I]);

        if (ind != -1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == temp[ind]) {
                        cout << i << ' ' << j << endl;
                        break;
                    }
                }
            }
        } else {
            cout << -1 << endl;
        }
    }

    // task D

    return 0;
}