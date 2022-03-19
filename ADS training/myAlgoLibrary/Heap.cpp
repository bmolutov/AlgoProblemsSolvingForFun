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
    int getMax () {
        return values[0];
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
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
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
                break;
            }
        }
    }
    void deleteRoot () {
        if (size > 0) {
            values[0] = values[--size];
            siftDown (0);
        }
    }
    void print () {
        for (int i = 0; i < size; i++) {
            cout << values[i] << ' ';
        } cout << '\n';
    }
    void increasePriority (int i, int x) {
        values[i] += x;
        siftUp (i);
    }
    void decreasePriority (int i, int x) {
        values[i] -= x;
        siftDown (i);
    }
    void extractMax () {
        int maximum = values[0];
        values[0] = values[--size];
        if (size != 0) {
            siftDown (0);
        }
        cout << maximum << '\n';
    }
    void deleteCustom (int index) {
        index--;
        cout << values[index] << '\n';
        int tempA = values[index], tempB = values[size - 1];
        swap (values[index], values[size - 1]);
        size--;
        if (tempA < tempB) {
            siftUp (index);
        } else {
            siftDown (index);
        }
    }
};

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    

    return 0;
}