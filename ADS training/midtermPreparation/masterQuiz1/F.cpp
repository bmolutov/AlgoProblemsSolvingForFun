#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int length = 100000;

struct Heap {
    int values[length]{};
    int size;
    Heap () {
        size = 0;
    }
    void siftUp (int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && values[i] < values[parent]) {
            swap (values[i], values[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
    void add (int x) {
        int i = size++;
        values[i] = x;
        siftUp (i);
    }
    void siftDown (int i) {
        while (2 * i + 1 < size) {
            int leftChild = 2 * i + 1, rightChild = 2 * i + 2, candidate = leftChild;
            if (rightChild < size) {
                if (values[rightChild] < values[leftChild]) {
                    candidate = rightChild;
                }
            }
            if (values[candidate] < values[i]) {
                swap (values[candidate], values[i]);
                i = candidate;
            } else {
                break;
            }
        }
    }
    int getMin () {
        return values[0];
    }
    void extractMin () {
        values[0] = values[--size];
        if (size != 0) {
            siftDown (0);
        }
    }
};

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Heap h;
    int n, min;
    cin >> n >> min;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.add (x);
    }
    int c = 0;
    while (h.getMin () < min) {
        int a = h.getMin (); h.extractMin ();
        if (h.size == 0)  {
            cout << -1;
            return 0;
        }
        int b = h.getMin (); h.extractMin ();
        h.add (a + 2 * b);
        c++;
    }
    cout << c;

    return 0;
}