#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

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
    void print (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            print (currentNode -> left, level + 1);
            cout << currentNode -> value << ' ';
            print (currentNode -> right, level + 1);
        }
    }
    int rightmost (Node * currentNode) {
        if (currentNode == nullptr) {
            return -1;
        }
        if (currentNode -> right == nullptr) {
            return currentNode -> value;
        } else {
            return rightmost (currentNode -> right);
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
    void deleteCustom (int target) {
        if (find (target)) {
            --elementsAmount;
            deleteCustom (root, target);
        }
    }
    bool find (int target) {
        return find (root, target);
    }
    void print () {
        print (root, 0);
        cout << '\n';
    }
    int size () const {
        return elementsAmount;
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