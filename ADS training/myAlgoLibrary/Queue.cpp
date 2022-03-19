#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    int value;
    Node * next;
    Node * prev;
    explicit Node (int x) {
        value = x;
        next = nullptr;
        prev = nullptr;
    }
};

struct Queue {
    Node * head;
    Node * tail;
    int length;
    Queue () {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    void push (int x) {
        length++;
        Node * item = new Node (x);
        if (head == nullptr) {
            head = tail = item;
        }
        else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop () {
        if (head != nullptr) {
            length--;
            head = head -> next;
            if (head != nullptr) {
                head -> prev = nullptr;
            }
        }
    }
    int front () const {
        if (head != nullptr) {
            return head -> value;
        }
        else {
            return (-1);
        }
    }
    int size () const {
        return length;
    }
    void clear () {
        length = 0;
        head = tail = nullptr;
    }
    bool empty () const {
        return length == 0;
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