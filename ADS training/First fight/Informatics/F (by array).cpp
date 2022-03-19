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
    string s; cin >> s;
    stack_ st;
    for (int i = 0; i < s.size(); i++) {
        if (st.size () == 0) {
            st.push (s[i]);
        }
        else {
            if (s[i] == '(') {
                st.push (s[i]);
                continue;
            }
            if (s[i] == '[') {
                st.push (s[i]);
                continue;
            }
            if (s[i] == '{') {
                st.push (s[i]);
                continue;
            }

            if (s[i] == ')' && st.back () == '(') {
                st.pop ();
                continue;
            }
            if (s[i] == ']' && st.back () == '[') {
                st.pop ();
                continue;
            }
            if (s[i] == '}' && st.back () == '{') {
                st.pop ();
                continue;
            }
            else st.push (s[i]);
        }
    }
    if (st.size () == 0) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    return 0;
}