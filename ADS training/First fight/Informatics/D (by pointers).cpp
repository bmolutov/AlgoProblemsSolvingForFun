#include <bits/stdc++.h>
using namespace std;

struct node {
    string value;
    node * next;
    node * prev;
    node (string x) {
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
    void push (string x) {
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
    string front () {
        if (head != NULL) {
            return head -> value;
        }
        else {
            return ("");
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
    int n;
    string s;
    Queue * q9 = new Queue;
    Queue * q10 = new Queue;
    Queue * q11 = new Queue;
    while (cin >> n && cin >> s) {
        if (n == 9) {
            q9 -> push (s);
        }
        else if (n == 10) {
            q10 -> push (s);
        }
        else if (n == 11) {
            q11 -> push (s);
        }
    }
    while (!q9 -> empty ()) {
        cout << 9 << ' ' << q9 -> front () << '\n';
        q9 -> pop ();
    }
    while (!q10 -> empty ()) {
        cout << 10 << ' ' << q10 -> front () << '\n';
        q10 -> pop ();
    }
    while (!q11 -> empty ()) {
        cout << 11 << ' ' << q11 -> front () << '\n';
        q11 -> pop ();
    }
    return 0;
}