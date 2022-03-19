// link: https://vjudge.net/problem/SPOJ-ADACLEAN

#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
typedef long long ll;
typedef unsigned long long ull;

const int p = 31;

struct Node {
public:
    ull value;
    Node * left;
    Node * right;
    explicit Node (ull x) {
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

struct BinarySearchTree {
private:
    Node * root;
    Node * add (Node * currentNode, ull candidate) {
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
    int size (Node * currentNode) {
        if (currentNode == nullptr) return 0;
        else return (size(currentNode -> left) + 1 + size(currentNode -> right));
    }

public:
    BinarySearchTree () {
        root = nullptr;
    }
    void add (ull newValue) {
        Node * result = add (root, newValue);
        if (root == nullptr) {
            root = result;
        }
    }
    int size () {
        return size (root);
    }
};

ull factors[100001];

void get_factors () {
    factors[0] = 1;
    for (int i = 1; i < 100001; i++) {
        factors[i] = factors[i - 1] * p;
    }
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    get_factors ();
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ull s_hash[n];
        for (int i = 0; i < n; i++) {
            s_hash[i] = (s[i] - 'a' + 1) * factors[i];
            if (i > 0) {
                s_hash[i] += s_hash[i - 1];
            }
        }

        auto * bst = new BinarySearchTree ();
        for (int i = 0; i + k - 1 < n; i++) {
            ull cur = s_hash[i + k - 1];
            if (i > 0) {
                cur -= s_hash[i - 1];
            }
            cur *= factors[n - i - 1];
            bst -> add (cur);
        }
        cout << bst -> size () << endl;
    }

    return 0;
}