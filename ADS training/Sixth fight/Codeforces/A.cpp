// link: https://codeforces.com/problemset/problem/4/C

#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
typedef long long ll;
typedef unsigned long long ull;

const int p = 31;

int tt;

struct Node {
public:
    string value;
    int amount;
    Node * left;
    Node * right;
    explicit Node (string x) {
        value = x;
        amount = 1;
        left = nullptr;
        right = nullptr;
    }
};

struct BinarySearchTree {
private:
    Node * root;
    Node * add (Node * currentNode, const string & candidate) {
        if (currentNode == nullptr) {
            return new Node (candidate);
        } else if (currentNode -> value < candidate) {
            currentNode -> right = add (currentNode -> right, candidate);
        }
        else if (currentNode -> value > candidate) {
            currentNode -> left = add (currentNode -> left, candidate);
        }
        return currentNode;
    }
    bool find (Node * currentNode, const string & target) {
        if (currentNode == nullptr) {
            return false;
        }
        if (currentNode -> value == target) {
            tt = currentNode -> amount;
            currentNode -> amount++;
            return true;
        }
        if (currentNode -> value > target) {
            return find (currentNode -> left, target);
        }
        if (currentNode -> value < target) {
            return find (currentNode -> right, target);
        }
        // extra, it is no necessary
        return false;
    }
    int size (Node * currentNode) {
        if (currentNode == nullptr) return 0;
        else return (size(currentNode -> left) + 1 + size(currentNode -> right));
    }

public:
    BinarySearchTree () {
        root = nullptr;
    }
    void add (const string & newValue) {
        if (!find (newValue)) {
            Node * result = add (root, newValue);
            if (root == nullptr) {
                root = result;
            }
            cout << "OK\n";
        } else {
            cout << newValue << tt << endl;
        }
    }
    bool find (const string & target) {
        return find (root, target);
    }
    int size () {
        return size (root);
    }
};

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    auto * bst = new BinarySearchTree ();
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        bst -> add (s);
    }

    return 0;
}