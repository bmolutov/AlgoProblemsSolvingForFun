#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

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
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    

    return 0;
}