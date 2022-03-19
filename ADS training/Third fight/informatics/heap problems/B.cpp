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
    void siftUp (int &i) {
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
    void siftDown (int &ii) {
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
    void del () {
        values[0] = values[--size];
        int ii = 0;
        siftDown (ii);
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
        h.add (x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int ii, x;
        cin >> ii >> x;
        ii--;
        h.decreasePriority (ii, x);
    }
    h.print ();
    return 0;
}