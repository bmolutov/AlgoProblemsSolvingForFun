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
    Deque * d1 = new Deque;
    Deque * d2 = new Deque;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        d1 -> push_back (x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        d2 -> push_back (x);
    }
    for (int i = 1; i <= 1e6; i++) {
        if(d1 -> front () > d2 -> front ()) {
            if(d1 -> front () == 9 && d2 -> front () == 0) {
                d2 -> push_back (d1 -> front ());
                d2 -> push_back (d2 -> front ());
                d1 -> pop_front ();
                d2 -> pop_front ();
            } else {
                d1 -> push_back (d1 -> front ());
                d1 -> push_back (d2 -> front ());
                d1 -> pop_front ();
                d2 -> pop_front ();
            }
        }
        else {
            if(d2 -> front () == 9 && d1 -> front () == 0) {
                d1 -> push_back (d1 -> front ());
                d1 -> push_back (d2 -> front ());
                d1 -> pop_front ();
                d2 -> pop_front ();
            } else {
                d2 -> push_back (d1 -> front ());
                d2 -> push_back (d2 -> front ());
                d1 -> pop_front ();
                d2 -> pop_front ();
            }
        }
        if (d1 -> size () == 0) {
            cout << "second " << i << '\n';
            return 0;
        }
        if (d2 -> size () == 0) {
            cout << "first " << i << '\n';
            return 0;
        }
    }
    cout << "botva\n";
    return 0;
}