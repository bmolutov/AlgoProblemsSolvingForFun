#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void mergeSort (int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort (a, l, m);
        mergeSort (a, m + 1, r);
        int n1 = m - l + 1, n2 = r - m;
        int left[n1], right[n2];
        for (int i = 0; i < n1; i++) left[i] = a[l + i];
        for (int i = 0; i < n2; i++) right[i] = a[m + 1 + i];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) a[k++] = left[i++];
            else a[k++] = right[j++];
        }
        while (i < n1) a[k++] = left[i++];
        while (j < n2) a[k++] = right[j++];
    }
}

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
    return a[r];
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort (a, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << bs (a, x, n) << endl;
    }

    return 0;
}