#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node {
    int value;
    Node * left;
    Node * right;
    explicit Node (int x) {
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

int ii = 0;

struct BinarySearchTree {
private:
    Node * root;
    int length;
    Node * add (Node * currentNode, int candidate) {
        if (currentNode == nullptr) {
            length++;
            return new Node (candidate);
        }
        if (candidate > currentNode -> value) {
            currentNode -> right = add (currentNode -> right, candidate);
        }
        if (candidate < currentNode -> value) {
            currentNode -> left = add (currentNode -> left, candidate);
        }
        return currentNode;
    }
    void traversal (Node * currentNode, int ans[]) {
        if (currentNode != nullptr) {
            traversal (currentNode -> left, ans);
            ans[ii++] = currentNode -> value;
            traversal (currentNode -> right, ans);
        }
    }
public:
    BinarySearchTree () {
        root = nullptr;
        length = 0;
    }
    void add (int newValue) {
        Node * result = add (root, newValue);
        if (root == nullptr) {
            root = result;
        }
    }
    void traversal () {
        int ans[length];
        traversal (root, ans);
        for (int i = length - 2; i >= 0; i--) {
            ans[i] += ans[i + 1];
        }
        for (int i = length - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }
    }
    int size () const {
        return length;
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
    bst -> traversal ();

    return 0;
}