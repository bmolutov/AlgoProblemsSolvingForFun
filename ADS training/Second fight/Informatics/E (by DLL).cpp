#include <bits/stdc++.h>
using namespace std;

struct node_str {
    string val;
    node_str * prev;
    node_str * next;
    node_str (string x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct dll_str {
    node_str * head;
    node_str * tail;
    int len;
    dll_str () {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    void add (string x) {
        node_str * newNode = new node_str (x);
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
    node_str * find (string x) {
        node_str * temp = head;
        node_str * result = NULL;
        while (temp != NULL) {
            if (temp -> val == x) {
                result = temp;
                break;
            }
            temp = temp -> next;
        }
        return result;
    }
    void del (node_str * n) {
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
    void del (string x) {
        node_str * temp = find (x);
        del (temp);
    }
    void print () {
        node_str * temp = head;
        while (temp != NULL) {
            cout << temp -> val << ' ';
            temp = temp -> next;
        }
        cout << '\n';
    }
    void reversed_print () {
        node_str * temp = tail;
        while (temp != NULL) {
            cout << temp -> val << ' ';
            temp = temp -> prev;
        }
        cout << '\n';
    }
    bool isEmpty () {
        return len == 0;
    }
};

struct node_int {
    int val;
    node_int * prev;
    node_int * next;
    node_int (int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct dll_int {
    node_int * head;
    node_int * tail;
    int len;
    dll_int () {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    void add (int x) {
        node_int * newNode = new node_int (x);
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
    node_int * find (int x) {
        node_int * temp = head;
        node_int * result = NULL;
        while (temp != NULL) {
            if (temp -> val == x) {
                result = temp;
                break;
            }
            temp = temp -> next;
        }
        return result;
    }
    void del (node_int * n) {
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
    void del (int x) {
        node_int * temp = find (x);
        del (temp);
    }
    void print () {
        node_int * temp = head;
        while (temp != NULL) {
            cout << temp -> val << ' ';
            temp = temp -> next;
        }
        cout << '\n';
    }
    void reversed_print () {
        node_int * temp = tail;
        while (temp != NULL) {
            cout << temp -> val << ' ';
            temp = temp -> prev;
        }
        cout << '\n';
    }
    bool isEmpty () {
        return len == 0;
    }
    void solve () {
        while (len != 0) {
            node_int * temp = head;
            node_int * mn = head;
            while (temp != NULL) {
                if (temp -> val < mn -> val) {
                    mn = temp;
                }
                temp = temp -> next;
            }
            cout << mn -> val << ' ';
            del (mn);
        }
    }
};

dll_int * List = new dll_int ();

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    string s;
    bool check = false;
    while (cin >> s) {
        int x = stoi (s.substr (1, s.size () - 1));
        if (s[0] == '+') {
            List -> add (x);
        }
        else {
            if (List -> find (x) == NULL) {
                check = true;
            }
            else {
                List -> del (x);
            }
        }
    }
    if (check) {
        cout << "ERROR\n";
        return 0;
    }
    if (List -> len == 0) {
        cout << "EMPTY\n";
    }
    else {
        List -> solve ();
    }
    return 0;
}