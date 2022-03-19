#include <bits/stdc++.h>
using namespace std;

const int len = 200000;

struct deque_ {
    int a[len];
    int leftIndex, rightIndex;
    deque_ () {
        leftIndex = len / 2;
        rightIndex = len / 2;
    }
    void push_front (int x) {
        a[leftIndex] = x;
        if (leftIndex == len / 2 && rightIndex == len / 2) {
            rightIndex++;
        }
        leftIndex--;
    }
    void push_back (int x) {
        a[rightIndex] = x;
        if (leftIndex == len / 2 && rightIndex == len / 2) {
            leftIndex--;
        }
        rightIndex++;
    }
    void pop_front () {
        leftIndex++;
        if (leftIndex > rightIndex) {
            leftIndex = len / 2;
            rightIndex = len / 2;
        }
    }
    void pop_back () {
        rightIndex--;
        if (leftIndex > rightIndex) {
            leftIndex = len / 2;
            rightIndex = len / 2;
        }
    }
    int front () {
        return a[leftIndex + 1];
    }
    int back () {
        return a[rightIndex - 1];
    }
    int size () {
        int ans = rightIndex - leftIndex - 1;
        if (ans == -1) {
            return 0;
        }
        else {
            return ans;
        }
    }
    void clear () {
        leftIndex = len / 2;
        rightIndex = len / 2;
    }
};

signed main () {
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    deque_ left, right;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char k;
        cin >> k;
        if (k == '-') {
            cout << left.front () << '\n';
            left.pop_front ();
        }
        else if (k == '+') {
            int t;
            cin >> t;
            right.push_back (t);
        }
        else {
            int t;
            cin >> t;
            right.push_front (t);
        }
        if (right.size () > left.size ()) {
            left.push_back (right.front ());
            right.pop_front ();
        }
    }
    return 0;
}