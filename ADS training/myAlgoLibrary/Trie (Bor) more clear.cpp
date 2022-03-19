#include <bits/stdc++.h>
using namespace std;

const int N = 3e3+5;

struct vert {
    int next[26]{};
    bool isEnd{};
    vert () {
        memset (next, -1, sizeof (next));
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
            cur = tree[cur].next[c];
        }
        tree[cur].isEnd = true;
    }
    bool search (const string & s) {
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
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        t.add (str);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> str;
        cout << t.search(str) << '\n';
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