#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

int partition (int a[], int l, int r) {
    int pivot = a[r];
    int pIndex = l;
    for (int i = l; i < r; i++) {
        if (a[i] <= pivot) {
            swap (a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex], a[r]);
    return pIndex;
}

void quickSort (int a[], int l, int r) {
    if (l < r) {
        int pIndex = partition (a, l, r);
        quickSort (a, l, pIndex - 1);
        quickSort (a, pIndex + 1, r);
    } else return;
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
    unsigned int seed = 0;
    shuffle (a, a + n, default_random_engine (seed));
    quickSort (a, 0, n - 1);

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            cnt++;
        }
    }
    cout << n - cnt;

    return 0;
}