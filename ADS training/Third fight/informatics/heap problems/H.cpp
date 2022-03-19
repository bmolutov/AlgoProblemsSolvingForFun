#include <bits/stdc++.h>
using namespace std;

const int length = 100000;

struct Heap {
    int values[length];
    int size;
    Heap () {
        size = 0;
    }
    int leftChildIndex (int ii) {
        return (2 * ii + 1);
    }
    int rightChildIndex (int ii) {
        return (2 * ii + 2);
    }
    int getMax () {
        return values[0];
    }
    void siftUp (int i) { // for one of the previous problems used &i
        int parent = (i - 1) / 2;
        while (i > 0 && values[i] > values[parent]) {
            swap (values[i], values[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
    // for building the heap by siftUp
    // this builds by default builds correct heap
    void add (int x) {
        int i = size++;
        values[i] = x;
        siftUp (i);
        // optional
        // cout << i + 1 << '\n';
    }
    // for building the heap by siftDown
    void addBySiftDown (int x) {
        int i = size++;
        values[i] = x;
//        int ii = (i - 1) / 2;
//        siftDown (ii);
    }
    void buildHeapBySiftDown () {
        for (int i = size / 2; i >= 0; i--) {
            siftDown (i);
        }
    }
    void siftDown (int ii) { // for one of the previous problems used &ii
        while (2 * ii + 1 < size) {
            int leftChild = leftChildIndex(ii);
            int rightChild = rightChildIndex(ii);
            int candidate = leftChild;
            if (rightChild < size) {
                if (values[rightChild] > values[leftChild]) {
                    candidate = rightChild;
                }
            }
            if (values[ii] < values[candidate]) {
                swap (values[ii], values[candidate]);
                ii = candidate;
            } else {
                // if the parent is incomparable
                break;
            }
        }
    }
    void deleteRoot () {
        if (size > 0) {
            values[0] = values[--size];
            int ii = 0;
            siftDown (ii);
        }
    }
    void print () {
        for (int i = 0; i < size; i++) {
            cout << values[i] << ' ';
        } cout << '\n';
    }
    void increasePriority (int ii, int x) {
        int answer = ii;
        values[ii] += x;
        siftUp (ii);
        answer = ii;
        // printing the final index
        cout << ++answer << '\n';
    }
    void decreasePriority (int ii, int x) {
        int answer = ii;
        values[ii] -= x;
        siftDown (ii);
        answer = ii;
        // printing the final index
        cout << ++answer << '\n';
    }
    void extractMax () {
        int maximum = values[0];
        values[0] = values[--size];
        int ii = 0;
        if (size != 0) {
            siftDown (ii);
        }
        else {
            ii = -1;
        }
        // printing the index of the sifted element and maximum
        cout << ++ii << ' ' << maximum << '\n';
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

Heap h;

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.addBySiftDown (x);
    }
    h.buildHeapBySiftDown ();
    h.print ();
    int answer[n];
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = h.getMax ();
        h.deleteRoot ();
        h.print ();
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}