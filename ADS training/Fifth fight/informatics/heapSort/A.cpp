#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

void heapify (int a[], int n, int i) {
    int candidate = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[candidate] < a[left]) candidate = left;
    if (right < n && a[candidate] < a[right]) candidate = right;
    if (candidate != i) {
        swap (a[i], a[candidate]);
        heapify (a, n, candidate);
    }
}

void heapSort (int a[], int n) {
    for (int i = n / 2; i >= 0; i--) heapify (a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap (a[0], a[i]);
        heapify (a, i, 0);
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
    heapSort (a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}