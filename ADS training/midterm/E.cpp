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

int left_level = 1, right_level = 1;
int main_cnt = 0;
int target;

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
    void goLeft (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            goLeft(currentNode->left, level + 1);
        } else {
            left_level = level;
        }
    }
    void goRight (Node * currentNode, int level) {
        if (currentNode != nullptr) {
            goRight(currentNode->right, level + 1);
        } else {
            right_level = level;
        }
    }
    void traversal (Node * currentNode) {
        if (currentNode != nullptr) {
            traversal(currentNode->left);
            //---> separator
            goLeft(currentNode->left, left_level);
            goRight(currentNode->right, right_level);
            if (left_level >= target && right_level >= target) {
                main_cnt++;
            }
//            cout << "t: " << target << endl;
//            cout << "l: " << left_level << endl;
//            cout << "r: " << right_level << endl << endl;
            left_level = 1; right_level = 1;
            //---> separator
            traversal(currentNode->right);
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
    int ans = 0;
    int a[n + 1];
    for (int i = 2; i <= n; i++) {
        target = i;
        bst -> traversal ();
        a[i] = main_cnt;
        main_cnt = 0;
    }
    for (int i = 2; i <= n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}

// problem E