#include <bits/stdc++.h>
using namespace std;

struct node {
    string value;
    int counter;
    node * prev;
    node * next;
    node (string val, int cnt) {
        value = val;
        counter = cnt;
        prev = NULL;
        next = NULL;
    }
};

struct dll {
    node * head;
    node * tail;
    int len;
    dll () {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    void add (string val) {
        node * newNode = new node (val, 1);
        len++;
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    node * find (string val) {
        node * temp = head;
        node * result = NULL;
        while (temp != NULL) {
            if (temp -> value == val) {
                result = temp;
                break;
            }
            temp = temp -> next;
        }
        return result;
    }
    void del (node * n) {
        if (n != NULL) {
            len--;
            if (n -> prev == NULL && n -> next == NULL) {
                head = tail = NULL;
            }
            else if (n -> prev != NULL && n -> next != NULL) {
                n -> prev -> next = n -> next;
                n -> next -> prev = n -> prev;
            }
            else if (n -> prev == NULL && n -> next != NULL) {
                head = n -> next;
                n -> next -> prev = NULL;
            }
            else if (n -> next == NULL && n -> prev != NULL) {
                tail = n -> prev;
                n -> prev -> next = NULL;
            }
            delete n;
        }
    }
    void del (string val) {
        node * temp = find (val);
        del (temp);
    }
    void print () {
        node * temp = head;
        while (temp != NULL) {
            cout << temp -> value << ' ' << temp -> counter << '\n';
            temp = temp -> next;
        }
    }
    void print_values () {
        node * temp = head;
        while (temp != NULL) {
            cout << temp -> value << ' ';
            temp = temp -> next;
        }
        cout << '\n';
    }
    void print_counters () {
        node * temp = head;
        while (temp != NULL) {
            cout << temp -> counter << ' ';
            temp = temp -> next;
        }
        cout << '\n';
    }
    bool isEmpty () {
        return len == 0;
    }
    node * swap(node * ptr1, node * ptr2) {
        node * tmp = ptr2 -> next;
        ptr2 -> next = ptr1;
        ptr1 -> next = tmp;
        return ptr2;
    }
    void solve () {
        while (len != 0) {
            node * mn = head;
            node * temp = head;
            while (temp != NULL) {
                if ((temp -> value) < (mn -> value)) {
                    mn = temp;
                }
                temp = temp -> next;
            }
            cout << mn -> value << ' ' << mn -> counter << '\n';
            del (mn);
        }
    }
};

dll * List = new dll ();

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    string s;
    while (cin >> s) {
        if (List -> find (s) == NULL) {
            List -> add (s);
        }
        else {
            List -> find (s) -> counter++;
        }
    }
    List -> solve ();
    return 0;
}