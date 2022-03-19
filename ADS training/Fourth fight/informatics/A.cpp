#include <bits/stdc++.h>
using namespace std;

int height = 0;

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
    }
    // this printing is based on inOrderTraversal
    void print (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            print (currentNode -> left, level + 1);
            cout << currentNode -> value << ' ' << level << '\n'; // check this
            print (currentNode -> right, level + 1);
        }
    }
    void preOrderTraversal (Node * currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            cout << currentNode -> value << ' ';
            preOrderTraversal (currentNode -> left);
            preOrderTraversal (currentNode -> right);
        }
    }
    void inOrderTraversal (Node * currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            inOrderTraversal (currentNode -> left);
            cout << currentNode -> value << ' ';
            inOrderTraversal (currentNode -> right);
        }
    }
    void postOrderTraversal (Node * currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            postOrderTraversal (currentNode -> left);
            postOrderTraversal (currentNode -> right);
            cout << currentNode -> value << ' ';
        }
    }
    int rightmost (Node * currentNode) {
        if (currentNode == nullptr) {
            return -1; // check this
        }
        if (currentNode -> right == nullptr) {
            return currentNode -> value;
        } else {
            return rightmost (currentNode -> right);
        }
    }
    int leftmost (Node * currentNode) {
        if (currentNode == nullptr) {
            return -1;
        }
        if (currentNode -> left == nullptr) {
            return currentNode -> value;
        } else {
            return leftmost (currentNode -> left);
        }
    }
    Node * deleteCustom (Node * currentNode, int target) {
        if (currentNode == nullptr) {
            return nullptr;
        }
        if (currentNode -> value == target) {
            if (currentNode -> right == nullptr && currentNode -> left == nullptr) {
                delete currentNode;
                return nullptr;
            } else if (currentNode -> left != nullptr && currentNode -> right == nullptr) {
                Node * temp = currentNode -> left;
                delete currentNode;
                return temp;
            } else if (currentNode -> right != nullptr && currentNode -> left == nullptr) {
                Node * temp = currentNode -> right;
                delete currentNode;
                return temp;
            } else if (currentNode -> right != nullptr && currentNode -> left != nullptr) {
                currentNode -> value = rightmost (currentNode -> left);
                currentNode -> left = deleteCustom (currentNode -> left, currentNode -> value);
            }
        } else if (currentNode -> value < target) {
            currentNode -> right = deleteCustom (currentNode -> right, target);
            return currentNode;
        } else if (currentNode -> value > target) {
            currentNode -> left = deleteCustom (currentNode -> left, target);
            return currentNode;
        }
        return currentNode;
    }
    void countLevels (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            countLevels (currentNode -> left, level + 1);
            countLevels (currentNode -> right, level + 1);
        } else {
            height = max (height, level);
        }
    }

public:
    BinarySearchTree () {
        root = nullptr;
    }
    void add (int newValue) {
        Node * result = add (root, newValue);
        if (root == nullptr) {
            root = result;
        }
    }
    void deleteCustom (int target) {
        deleteCustom (root, target);
    }
    bool find (int target) {
        return find (root, target);
    }
    void print () {
        print (root, 0);
        cout << '\n';
    }
    // with printing
    void preOrderTraversal () {
        preOrderTraversal (root);
        cout << '\n';
    }
    // with printing
    void inOrderTraversal () {
        inOrderTraversal (root);
        cout << '\n';
    }
    // with printing
    void postOrderTraversal () {
        postOrderTraversal (root);
        cout << '\n';
    }
    // for calculating the height of the tree
    void countLevels () {
        countLevels (root, 0);
    }
};

signed main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (nullptr);
    auto * bst = new BinarySearchTree ();
    int x;
    while (true) {
        cin >> x;
        if (x == 0) {
            break;
        } else {
            bst -> add (x);
        }
    }
    bst -> countLevels ();
    cout << height;
    return 0;
}