#include <bits/stdc++.h>
using namespace std;

const int len = 100000;

struct stack_ {
    int a[len];
    int rightIndex;
    stack_ () {
        rightIndex = -1;
    }
    void push (int x) {
        rightIndex++;
        a[rightIndex] = x;
    }
    void pop () {
        rightIndex--;
    }
    int back () {
        return a[rightIndex];
    }
    int size () {
        return (rightIndex + 1);
    }
    void clear () {
        rightIndex = -1;
    }
};

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    string s;
    getline (cin, s);
    stack_ st;
    for (char i: s) {
        if (i == '+' || i == '-' || i == '*') {
            int first = st.back ();
            st.pop ();
            int second = st.back ();
            st.pop ();
            int res;
            if (i == '+') {
                res = second + first;
            }
            else if (i == '-') {
                res = second - first;
            }
            else {
                res = second * first;
            }
            st.push (res);
        }
        else if (i >= '0' && i <= '9') {
            st.push (int (i - 48));
        }
    }
    if ((int) st.size () != 0) {
        cout << st.back () << '\n';
    }
    return 0;
}