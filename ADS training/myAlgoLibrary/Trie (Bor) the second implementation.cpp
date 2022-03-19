#include <bits/stdc++.h>
using namespace std;

struct Node {
    int count;
    int child[26]{};
    Node () {
        count = 0;
        memset (child, -1, sizeof (child));
    }
};

vector <Node> data;

void insert (int head, const string& s) {
    int cur = head;
    for (char i : s) {
        int chIndex = i - 'a';
        if (data[cur].child[chIndex] == -1) {
            data[cur].child[chIndex] = (int) data.size ();
            data.emplace_back();
        }
        cur = data[cur].child[chIndex];
        ++data[cur].count;
    }
}

int find (int head, const string& s) {
    int cur = head;
    for (char i : s) {
        int chIndex = i - 'a';
        if (data[cur].child[chIndex] == -1) {
            return 0; // prefix is not in the dictionary
        }
        cur = data[cur].child[chIndex];
    }
    // we reached the node representing our word
    return data[cur].count;
}

void solve () {
    data.emplace_back();
    // https://www.commonlounge.com/discussion/f0a9acb28617471cb286d84c68a0d210
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