#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

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
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    

    return 0;
}