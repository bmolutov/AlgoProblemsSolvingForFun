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
            cout << temp -> val << '\n';
            temp = temp -> next;
        }
//        cout << '\n';
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
    void swap(node_str * r, node_str * s) {
        node_str temp = * r;
        * r = * s;
        * s = temp;
        return;
    }
    void swap2 (node_str * p1, node_str * p2) {
        string temp = p1 -> val;
        p1 -> val = p2 -> val;
        p2 -> val = temp;
        return;
    }
    void transit (node_str * temp) {
        node_str * temp2 = tail;
        while (temp2 != temp) {
            swap2 (temp2, temp2 -> prev);
            temp2 = temp2 -> prev;
        }
    }
};

dll_str * List = new dll_str ();

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    string s;
    while (getline (cin, s)) {
        int num;
        char sign = s[0];
        int Len;
        string res;
        for (Len = 1; Len < (int) s.size (); Len++) {
            if (s[Len] == ' ') {
                break;
            }
        }
        num = stoi (s.substr (1, Len - 1));
        if (sign == '+' || sign == '*') {
            res = s.substr (1 + Len, (int) s.size () - 1 - Len);
            if (sign == '+') {
                if (num > List -> len + 1) {
                    cout << "ERROR\n";
                    return 0;
                }
                node_str * temp = List -> head;
                for (int i = 0; i < num - 1;) {
                    if (temp != NULL) {
                        i++;
                    }
                    temp = temp -> next;
                }
                if (temp == NULL) {
                    List -> add (res);
                }
                else {
                    List -> add (res);
                    List -> transit (temp);
                }
            }
            else {
                if (num > List -> len + 1) {
                    cout << "ERROR\n";
                    return 0;
                }
                node_str * temp = List -> head;
                for (int i = 0; i < num - 1;) {
                    if (temp != NULL) i++;
                    temp = temp -> next;
                }
                if (temp != NULL) {
                    temp -> val = res;
                }
                else {
                    cout << "ERROR\n";
                    return 0;
                }
            }
        }
        else {
            if (num > List -> len + 1) {
                cout << "ERROR\n";
                return 0;
            }
            node_str * temp = List -> head;
            for (int i = 0; i < num - 1;) {
                if (temp != NULL) i++;
                temp = temp -> next;
            }
            if (temp != NULL) {
                List -> del (temp);
            }
            else {
                cout << "ERROR\n";
                return 0;
            }
        }
    }
    if (List -> len == 0) {
        cout << "EMPTY\n";
    }
    else {
        List -> print ();
    }
    return 0;
}