#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

void mergeSort (int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort (a, l, m);
        mergeSort (a, m + 1, r);
        int n1 = m - l + 1, n2 = r - m;
        int left[n1], right[n2];
        for (int i = 0; i < n1; i++) left[i] = a[l+i];
        for (int i = 0; i < n2; i++) right[i] = a[m+1+i];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) a[k++] = left[i++];
            else a[k++] = right[j++];
        }
        while (i < n1) a[k++] = left[i++];
        while (j < n2) a[k++] = right[j++];
    }
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    mergeSort (a, 0, n - 1);
    mergeSort (b, 0, m - 1);

    int i = 0, j = 0;
    bool check = true;
    while (i < n && j < m) {
        bool c1 = false, c2 = false;
        int temp = a[i];
        while (a[i] == temp) {
            i++;
            c1 = true;
        }
        while (b[j] == temp) {
            j++;
            c2 = true;
        }
        if (!c1 || !c2) {
            check = false;
            break;
        }
    }
    if (i != n) check = false;
    if (j != m) check = false;
    if (check) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}