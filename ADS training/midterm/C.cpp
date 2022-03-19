#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int ans;
    Node *prev;
    Node(int x) {
        value = x;
        prev = nullptr;
        ans = -1;
    }
};

struct Stack {
private:
    Node *head = nullptr;
    int sz = 0;
public:

    int top() {
        return head->value;
    }

    void pop() {
        head = head->prev;
        sz--;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    int push(int x) {
        Node * node = new Node(x);
        // write your code here
        sz++;
        if (head == nullptr) {
            head = node;
        } else {
            node -> prev = head;
            head = node;
        }

        Node * temp = node -> prev;
        while (temp != nullptr) {
            if (temp -> value <= node -> value) {
                node -> ans = temp -> value;
                break;
            }
            temp = temp -> prev;
        }

        return node->ans;
    }

}st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << st.push(x) << ' ';
    }
}
// problem C