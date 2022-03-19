#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v1, v2, w;
};

const int N = 1e5;

void solve () {
    int n, m;
    cin >> n >> m;
    vector <Edge> edges;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges.push_back (Edge {v1, v2, w});
    }
    sort (edges.begin (), edges.end (), [](const Edge &left, const Edge &right) {
        return left.w < right.w;
    });
    vector <int> parent (1 + n, -1); // parent[v] >= 0 - parent node, parent[0] < 0 - -size
    function <int (int)> getRoot = [&](int v) {
        if (parent[v] < 0) {
            return v;
        } else {
            int root = getRoot (parent[v]);
            parent[v] = root;
            return root;
        }
    };
    function <bool (int, int)> join = [&](int a, int b) {
        a = getRoot (a);
        b = getRoot (b);
        if (a == b) {
            return false;
        }
        assert (parent[a] < 0);
        assert (parent[b] < 0);
        if (parent[a] < parent[b]) {
            parent[a] += parent[b];
            parent[b] = a;
        } else {
            parent[b] += parent[a];
            parent[a] = b;
        }
        return true;
    };
    int sum = 0;
    int count = 0;
    for (const Edge &e : edges) {
        if (join (e.v1, e.v2)) {
            sum += e.w;
            count++;
        }
    }
    assert (count == n - 1);
    cout << sum;
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