#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

int a[505][505];

bool comp (int A[], int B[], int m) {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < m; i++) {
        sumA += A[i];
        sumB += B[i];
    }
    if (sumA > sumB) {
        return true;
    } else if (sumA == sumB) {
        for (int i = 0; i < m; i++) {
            if (A[i] <= B[i]) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

void mergeSort (int l, int r, int n, int m) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort (l, mid, n, m);
        mergeSort (mid + 1, r, n, m);

        int n1 = mid - l + 1, n2 = r - mid;
        int left[n1][m], right[n2][m];

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m; j++) {
                left[i][j] = a[l + i][j];
            }
        }
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m; j++) {
                right[i][j] = a[mid + 1 + i][j];
            }
        }
        int ii = 0, jj = 0, kk = l;
        while (ii < n1 && jj < n2) {
            if (comp (left[ii], right[jj], m)) {
                for (int i = 0; i < m; i++) {
                    a[kk][i] = left[ii][i];
                }
                ii++;
                kk++;
            } else {
                for (int i = 0; i < m; i++) {
                    a[kk][i] = right[jj][i];
                }
                jj++;
                kk++;
            }
        }
        while (ii < n1) {
            for (int i = 0; i < m; i++) {
                a[kk][i] = left[ii][i];
            }
            ii++;
            kk++;
        }
        while (jj < n2) {
            for (int i = 0; i < m; i++) {
                a[kk][i] = right[jj][i];
            }
            jj++;
            kk++;
        }
    }
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    mergeSort (0, n - 1, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        } cout << endl;
    }

    return 0;
}

// problem A