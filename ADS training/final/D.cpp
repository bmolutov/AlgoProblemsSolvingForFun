#include <bits/stdc++.h>
using namespace std;

int l = 0, r = 0, mx = INT_MIN;
int lMax, rMax;

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
    int elementsAmount;
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
    bool find (Node * currentNode, int target) {
        if (currentNode == nullptr) {
            return false;
        }
        if (currentNode -> value == target) {
            return true;
        }
        if (currentNode -> value > target) {
            return find (currentNode -> left, target);
        }
        if (currentNode -> value < target) {
            return find (currentNode -> right, target);
        }
        return false;
    }
    void traversalLeft (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            traversalLeft (currentNode -> left, level + 1);
            traversalLeft (currentNode -> right, level + 1);
        } else {
            lMax = max (lMax, level);
        }
    }
    void traversalRight (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            traversalRight (currentNode -> left, level + 1);
            traversalRight (currentNode -> right, level + 1);
        } else {
            rMax = max (rMax, level);
        }
    }
    void traversalMain (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            traversalMain (currentNode -> left, level + 1);

            traversalLeft (currentNode -> left, 0);
            traversalRight (currentNode -> right, 0);
            mx = max (mx, (lMax + rMax));
            lMax = 0, rMax = 0;

            traversalMain (currentNode -> right, level + 1);
        }
    }

public:
    BinarySearchTree () {
        root = nullptr;
        elementsAmount = 0;
    }
    void add (int newValue) {
        if (!find (newValue)) {
            ++elementsAmount;
            Node *result = add(root, newValue);
            if (root == nullptr) {
                root = result;
            }
        }
    }
    bool find (int target) {
        return find (root, target);
    }
    void traversalMain () {
        traversalMain(root, 0);
    }
    int size () const {
        return elementsAmount;
    }
};

void solve () {
    auto * bst = new BinarySearchTree ();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst -> add (x);
    }
    bst -> traversalMain ();
    cout << mx + 1;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//    #endif
    solve ();
    return 0;
}