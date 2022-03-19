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

struct Queue {
    node * head;
    node * tail;
    int len;
    Queue () {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    void push (int x) {
        len++;
        node * item = new node (x);
        if (head == NULL) {
            head = tail = item;
        }
        else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop () {
        if (head != NULL) {
            len--;
            head = head -> next;
            if (head != NULL) {
                head -> prev = NULL;
            }
        }
    }
    int front () {
        if (head != NULL) {
            return head -> value;
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
        head = tail = NULL;
    }
    bool empty () {
        return len == 0;
    }
};

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    string s;
    Queue * q = new Queue;
    while (true) {
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            q -> push (n);
            cout << "ok\n";
        }
        else if (s == "pop") {
            if (q -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << q -> front () << '\n';
                q -> pop ();
            }
        }
        else if (s == "front") {
            if (q -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << q -> front () << '\n';
            }
        }
        else if (s == "size") {
            cout << q -> size () << '\n';
        }
        else if (s == "clear") {
            q -> clear ();
            cout << "ok\n";
        }
        else if (s == "exit") {
            cout << "bye\n";
            break;
        }
    }
    return 0;
}