#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

const int length = 500000;

struct Heap {
    int values[length];
    int size;
    Heap () {
        size = 0;
    }
    void siftUp (int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && values[i] > values[parent]) {
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
            int leftChild = 2 * i + 1, rightChild = 2 * i + 2;
            int candidate = leftChild;
            if (rightChild < size) {
                if (values[rightChild] > values[leftChild]) {
                    candidate = rightChild;
                }
            }
            if (values[i] < values[candidate]) {
                swap (values[i], values[candidate]);
                i = candidate;
            } else {
                // if the parent is quite big
                break;
            }
        }
    }
    void extractMax () {
        int maximum = values[0];
        cout << maximum << endl;
        values[0] = values[--size];
        if (size != 0) {
            siftDown (0);
        } else return;
    }
};

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int check;
        cin >> check;
        if (check == 1) {
            h.extractMax ();
        } else {
            int x;
            cin >> x;
            h.add (x);
        }
    }

    return 0;
}