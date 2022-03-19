#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int ans = 0;

struct Node {
public:
    int value;
    Node * left;
    Node * right;
    explicit Node (int x) {
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

struct BinarySearchTree {
private:
    Node * root;
    Node * add (Node * currentNode, int candidate) {
        if (currentNode == nullptr) {
            return new Node (candidate);
        }
        if (currentNode -> value < candidate) {
            currentNode -> right = add (currentNode -> right, candidate);
        }
        if (currentNode -> value > candidate) {
            currentNode -> left = add (currentNode -> left, candidate);
        }
        return currentNode;
    }
    void traversal (Node * currentNode) {
        if (currentNode != nullptr) {
            traversal (currentNode -> left);
            if (currentNode -> left != nullptr && currentNode -> right != nullptr) {
                ans++;
            }
            traversal (currentNode -> right);
        }
    }
public:
    BinarySearchTree () {
        root = nullptr;
    }
    void add (int x) {
        Node * result = add (root, x);
        if (root == nullptr) {
            root = result;
        }
    }
    void traversal () {
        traversal (root);
    }
};

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    auto * bst = new BinarySearchTree ();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst -> add (x);
    }
    bst->traversal();
    cout << ans << endl;

    return 0;
}