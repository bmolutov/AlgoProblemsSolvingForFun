#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

struct vert {
    int next[26];
    bool isEnd;
};

vert tree[N];
int sz = 1;

void init () {
    for (int & i : tree[0].next) {
        i = -1;
    }
}

void add (const string & s) {
    int cur = 0;
    for (char i : s) {
        int c = i - 'a';
        if (tree[cur].next[c] == -1) {
            for (int & j : tree[sz].next) {
                j = -1;
            }
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

void solve () {
    int n;
    cin >> n;
    string str;
    init ();
    for(int i = 0; i < n; ++i){
        cin >> str;
        add (str);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> str;
        cout << search(str) << '\n';
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