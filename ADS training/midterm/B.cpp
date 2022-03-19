#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);


const int length = 100000;

struct Heap {
    long long values[length]{};
    int size;
    Heap () {
        size = 0;
    }
    long long getMin () {
        return values[0];
    }
    void siftUp (int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && values[i] < values[parent]) {
            swap (values[i], values[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
    void add (long long x) {
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
                if (values[rightChild] < values[leftChild]) {
                    candidate = rightChild;
                }
            }
            if (values[i] > values[candidate]) {
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
};

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        h.add (x);
    }
    long long ans = 0;
    while (h.size > 1) {
        long long a = h.getMin ();
        h.deleteRoot ();
        long long b = h.getMin ();
        h.deleteRoot ();
//        cout << a << ' ' << b << endl;
        ans += (a + b);
        h.add (a + b);
    }
    cout << ans;

    return 0;
}

// problem B