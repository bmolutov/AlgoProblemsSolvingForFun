#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    char value;
    Node * prev;
    Node * next;
    explicit Node (char x) {
        value = x;
        prev = nullptr;
        next = nullptr;
    }
};

struct Stack {
    Node * tail;
    int length;
    Stack () {
        tail = nullptr;
        length = 0;
    }
    void push (char x) {
        length++;
        Node * item = new Node (x);
        if (tail == nullptr) {
            tail = item;
        } else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop () {
        if (tail != nullptr) {
            length--;
            tail = tail -> prev;
        } else return;
    }
    char top () const {
        if (tail != nullptr) {
            return tail -> value;
        } else {
            return -1;
        }
    }
    int size () const {
        return length;
    }
    void clear () {
        length = 0;
        tail = nullptr;
    }
    bool empty () const {
        return tail == nullptr;
    }
};

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    Stack st;
    string s;
    cin >> s;
    for (auto & i: s) {
        if (st.empty ()) {
            st.push (i);
        } else {
            if (st.top () == '(' && i == ')') {
                st.pop ();
            } else if (st.top () == '[' && i == ']') {
                st.pop ();
            } else if (st.top () == '{' && i == '}') {
                st.pop ();
            } else {
                st.push (i);
            }
        }
    }
    if (st.empty ()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}