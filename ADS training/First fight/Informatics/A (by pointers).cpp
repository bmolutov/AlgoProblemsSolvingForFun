#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node * next;
    node * prev;
    node (int x) {
        value = x;
        next = NULL;
        prev = NULL;
    }
};

struct Stack {
    node * tail;
    int len;
    Stack () {
        tail = NULL;
        len = 0;
    }
    void push (int x) {
        len++;
        node * item = new node (x);
        if (tail == NULL) {
            tail = item;
        }
        else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop () {
        if (tail != NULL) {
            len--;
            tail = tail -> prev;
            if (tail != NULL) {
                tail -> next = NULL;
            }
        }
    }
    int top () {
        if (tail != NULL) {
            return tail -> value;
        }
        else {
            return (-1);
        }
    }
    int size () {
        return len;
    }
    void clear () {
        len = 0;
        tail = NULL;
    }
    bool empty () {
        return tail == NULL;
    }
};

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    string s;
    Stack * st = new Stack;
    while (true) {
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            st -> push (n);
            cout << "ok\n";
        }
        else if (s == "pop") {
            if (st -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << st -> top () << '\n';
                st -> pop ();
            }
        }
        else if (s == "back") {
            if (st -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << st -> top () << '\n';
            }
        }
        else if (s == "size") {
            cout << st -> size () << '\n';
        }
        else if (s == "clear") {
            st -> clear ();
            cout << "ok\n";
        }
        else if (s == "exit") {
            cout << "bye\n";
            break;
        }
    }
    return 0;
}