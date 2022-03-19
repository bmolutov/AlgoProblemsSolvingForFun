#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

const int length = 1e5;

struct Pair {
    int value{}, index{};
    Pair () = default;
};

struct Heap {
    Pair array[length]{};
    int size;
    Heap () {
        size = 0;
    }
    int getMin () {
        return array[0].value;
    }
    void siftUp (int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && array[i].value < array[parent].value) {
            swap (array[i], array[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
    void add (int value, int index) {
        int i = size++;
        array[i].value = value; array[i].index = index;
        siftUp (i);
    }
    void siftDown (int i) {
        while (2 * i + 1 < size) {
            int leftChild = 2 * i + 1, rightChild = 2 * i + 2, candidate = leftChild;
            if (rightChild < size) {
                if (array[rightChild].value < array[leftChild].value) {
                    candidate = rightChild;
                }
            }
            if (array[i].value > array[candidate].value) {
                swap (array[i], array[candidate]);
                i = candidate;
            } else break;
        }
    }
    void deleteRoot () {
        if (size > 0) {
            array[0] = array[--size];
            siftDown (0);
        } else return;
    }
    void print () {
        for (int i = 0; i < size; i++) {
            cout << array[i].value << ' ' << array[i].index << endl;
        }
    }
    void balance (int i, int k) {
        while (array[0].index < i - k + 1) {
            deleteRoot ();
        }
    }
};

// we are going to delete a node while the index is smaller than n - i + 1

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Heap hp;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        hp.add (x, i);
    }
    cout << hp.getMin () << endl;
    for (int i = k; i < n; i++) {
        int x;
        cin >> x;
        hp.add (x, i);
        hp.balance (i, k);
        cout << hp.getMin () << endl;
    }

    return 0;
}