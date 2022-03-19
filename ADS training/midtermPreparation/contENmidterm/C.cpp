#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    string value;
    Node * next;
    Node * prev;
    explicit Node (string x) {
        value = x;
        next = nullptr;
        prev = nullptr;
    }
};

struct Deque {
    Node * head;
    Node * tail;
    int length;
    Deque () {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    void push_front (string x) {
        length++;
        Node * item = new Node (x);
        if (head == nullptr) {
            head = tail = item;
        }
        else {
            head -> prev = item;
            item -> next = head;
            head = item;
        }
    }
    void push_back (string x) {
        length++;
        Node * item = new Node (x);
        if (tail == nullptr) {
            tail = head = item;
        }
        else {
            tail -> next = item;
            item -> prev = tail;
            tail = item;
        }
    }
    void pop_front () {
        if (head != nullptr) {
            length--;
            head = head -> next;
            if (head != nullptr) {
                head -> prev = nullptr;
            }
        }
        if (tail == nullptr || head == nullptr) {
            tail = nullptr; head = nullptr; length = 0;
        }
    }
    void pop_back () {
        if (tail != nullptr) {
            length--;
            tail = tail -> prev;
            if (tail != nullptr) {
                tail -> next = nullptr;
            }
        }
        if (tail == nullptr || head == nullptr) {
            tail = nullptr; head = nullptr; length = 0;
        }
    }
    string front () const {
        if (head != nullptr) {
            return head -> value;
        }
        else {
            return ("");
        }
    }
    string back () const {
        if (tail != nullptr) {
            return tail -> value;
        }
        else {
            return ("");
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

    Deque d;
    for (int i = 0; i < 52; i++) {
        string s;
        cin >> s;
        d.push_back (s);
    }
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < sum; i++) {
        d.push_back(d.front ());
        d.pop_front ();
    }
    cout << d.front () << endl;
    d.pop_front ();
    cout << d.front ();

    return 0;
}