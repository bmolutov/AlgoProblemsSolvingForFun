#include <bits/stdc++.h>
using namespace std; // Problem G

const int N = 1e6+5;

struct vert {
    int next[26]{};
    bool isEnd{};
    int qt[26]{};
    vert () {
        memset (next, -1, sizeof (next));
        isEnd = false;
        memset (qt, 0, sizeof (qt));
    }
};

struct Trie {
    vector <vert> tree;
    int sz;
    Trie () {
        tree.resize (N);
        sz = 1;
    }
    void add (const string & s) {
        int cur = 0;
        for (char i : s) {
            int c = i - 'a';
            if (tree[cur].next[c] == -1) {
                tree[cur].next[c] = sz++;
            }
            tree[cur].qt[c]++; // new!
            cur = tree[cur].next[c];
        }
        tree[cur].isEnd = true;
    }
    int count (const string & s) { // bool
        int cur = 0;
        for (int i = 0; i < (int) s.size (); i++) {
            int c = s[i] - 'a';
            if (tree[cur].next[c] == -1) {
                return 0;
            }
            if (i == (int) s.size () - 1) continue;
            cur = tree[cur].next[c];
        }
        return tree[cur].qt[s.back () - 'a']; // new
    }
    void del (const string & s) {
        int cur = 0;
        for (char i : s) {
            int c = i - 'a';
            if (tree[cur].qt[c] != 0) {
                tree[cur].qt[c]--; // new!
            }
            if (tree[cur].next[c] == 0) {
                tree[cur].next[c] = -1;
            }
            cur = tree[cur].next[c];
        }
        tree[cur].isEnd = false;
    }
    bool find (const string & s) {
        int cur = 0;
        for (char i : s) {
            int c = i - 'a';
            if (tree[cur].next[c] == -1) {
                return false;
            }
            cur = tree[cur].next[c];
        }
        return tree[cur].isEnd;
    }
};

void solve () {
    Trie t;
    int q;
    cin >> q;
    while (q--) {
        char k;
        string s;
        cin >> k >> s;
        if (k == '+') {
            t.add (s);
        } else if (k == '-') {
            if (t.find (s)) {
                t.del (s);
            }
        } else {
            cout << t.count (s) << '\n';
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve ();
    return 0;
}