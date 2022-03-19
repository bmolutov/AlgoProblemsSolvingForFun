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

struct Deque {
    node * head;
    node * tail;
    int len;
    Deque () {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    void push_front (int x) {
        len++;
        node * item = new node (x);
        if (head == NULL) {
            head = tail = item;
        }
        else {
            head -> prev = item;
            item -> next = head;
            head = item;
        }
    }
    void push_back (int x) {
        len++;
        node * item = new node (x);
        if (tail == NULL) {
            tail = head = item;
        }
        else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop_front () {
        if (head != NULL) {
            len--;
            head = head -> next;
            if (head != NULL) {
                head -> prev = NULL;
            }
        }
        if (tail == NULL || head == NULL) {
            tail = NULL; head = NULL; len = 0;
        }
    }
    void pop_back () {
        if (tail != NULL) {
            len--;
            tail = tail -> prev;
            if (tail != NULL) {
                tail -> next = NULL;
            }
        }
        if (tail == NULL || head == NULL) {
            tail = NULL; head = NULL; len = 0;
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
    int back () {
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
    Deque * d = new Deque;
    while (true) {
        cin >> s;
        if (s == "push_front") {
            int n;
            cin >> n;
            d -> push_front (n);
            cout << "ok\n";
        }
        else if (s == "push_back") {
            int n;
            cin >> n;
            d -> push_back (n);
            cout << "ok\n";
        }
        else if (s == "pop_front") {
            if (d -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << d -> front () << '\n';
                d -> pop_front ();
            }
        }
        else if (s == "pop_back") {
            if (d -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << d -> back () << '\n';
                d -> pop_back ();
            }
        }
        else if (s == "front") {
            if (d -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << d -> front () << '\n';
            }
        }
        else if (s == "back") {
            if (d -> empty ()) {
                cout << "error\n";
            }
            else {
                cout << d -> back () << '\n';
            }
        }
        else if (s == "size") {
            cout << d -> size () << '\n';
        }
        else if (s == "clear") {
            d -> clear ();
            cout << "ok\n";
        }
        else if (s == "exit") {
            cout << "bye\n";
            break;
        }
    }
    return 0;
}