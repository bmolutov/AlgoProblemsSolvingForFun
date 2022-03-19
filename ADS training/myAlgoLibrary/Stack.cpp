#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    int value;
    Node * prev;
    Node * next;
    explicit Node (int x) {
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
    void push (int x) {
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
    int top () const {
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
        tail = nullptr;
        length = 0;
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

    

    return 0;
}