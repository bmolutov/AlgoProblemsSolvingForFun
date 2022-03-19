#include <bits/stdc++.h>
using namespace std;

const int length = 100000;
int n;

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
        // optional
        cout << i + 1 << '\n';
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
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            if (h.size == 0) {
                cout << -1 << '\n';
            } else {
                h.extractMax ();
            }
        } else if (q == 2) {
            int x;
            cin >> x;
            if (h.size == n) {
                cout << -1 << '\n';
            } else {
                h.add (x);
            }
        } else if (q == 3) {
            int index;
            cin >> index;
            if (index < 1 || index > h.size) {
                cout << -1 << '\n';
            } else {
                h.deleteCustom (index);
            }
        }
    }
    h.print ();
    return 0;
}