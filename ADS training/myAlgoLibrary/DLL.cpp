#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    int value;
    Node * prev;
    Node * next;
    explicit Node (int x) {
        value = x;
        prev = nullptr;
        next = nullptr;
    }
};

struct DLL {
    Node * head;
    Node * tail;
    int len;
    DLL () {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    void add (int x) {
        Node * newNode = new Node (x);
        len++;
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    Node * find (int x) const {
        Node * temp = head;
        Node * result = nullptr;
        while (temp != nullptr) {
            if (temp -> value == x) {
                result = temp;
                break;
            }
            temp = temp -> next;
        }
        return result;
    }
    void deleteCustom (Node * currentNode) {
        if (currentNode != nullptr) {
            len--;
            if (currentNode -> prev == nullptr && currentNode -> next == nullptr) {
                head = tail = nullptr;
            }
            else if (currentNode -> prev != nullptr && currentNode -> next != nullptr) {
                currentNode -> prev -> next = currentNode -> next;
                currentNode -> next -> prev = currentNode -> prev;
            }
            else if (currentNode -> prev == nullptr && currentNode -> next != nullptr) {
                head = currentNode -> next;
                currentNode -> next -> prev = nullptr;
            }
            else if (currentNode -> next == nullptr && currentNode -> prev != nullptr) {
                tail = currentNode -> prev;
                currentNode -> prev -> next = nullptr;
            }
            delete currentNode;
        }
    }
    void deleteCustom (int x) {
        Node * temp = find (x);
        deleteCustom(temp);
    }
    void print () const {
        Node * temp = head;
        while (temp != nullptr) {
            cout << temp -> value << ' ';
            temp = temp -> next;
        }
        cout << '\n';
    }
    bool isEmpty () const {
        return len == 0;
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