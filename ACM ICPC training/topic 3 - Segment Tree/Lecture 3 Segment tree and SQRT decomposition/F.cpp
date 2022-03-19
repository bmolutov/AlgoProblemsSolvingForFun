#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define debug (x) cerr << #x << " "; print_ (x); cerr << endl;
#else
#define debug(x)
#endif
void print_ (long long t) {cerr << t;}
void print_ (int t) {cerr << t;}
void print_ (const string & t) {cerr << t;}
void print_ (char t) {cerr << t;}
void print_ (long double t) {cerr << t;}
void print_ (double t) {cerr << t;}
void print_ (unsigned long long t) {cerr << t;}
template <class T, class V> void print_ (pair <T, V> p);
template <class T> void print_ (vector <T> v);
template <class T> void print_ (set <T> v);
template <class T, class V> void print_ (map <T, V> v);
template <class T> void print_ (multiset <T> v);
template <class T, class V> void print_ (pair <T, V> p) {cerr << "{"; print_ (p.ff); cerr << ","; print_ (p.ss); cerr << "}";}
template <class T> void print_ (vector <T> v) {cerr << "[ "; for (T i : v) {print_ (i); cerr << " ";} cerr << "]";}
template <class T> void print_ (set <T> v) {cerr << "[ "; for (T i : v) {print_ (i); cerr << " ";} cerr << "]";}
template <class T> void print_ (multiset <T> v) {cerr << "[ "; for (T i : v) {print_ (i); cerr << " ";} cerr << "]";}
template <class T, class V> void print_ (map <T, V> v) {cerr << "[ "; for (auto i : v) {print_ (i); cerr << " ";} cerr << "]";}

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct SegTree {
        vector <pair <int, int>> tree;
        int size{};

        void init (int n) {
            size = 1;
            while (size < n) size *= 2;
            tree.assign (2 * size - 1, {INT_MIN, INT_MIN});
        }

        static pair <int, int> getMax (int a, int b, int c, int d) {
            vector <int> v = {a, b, c, d};
            pair <int, int> ans;

            int mxv1 = INT_MIN, mxv2 = INT_MIN;
            int mx1 = 0, mx2 = 0;
            for (int i = 0; i < 4; i++) {
                if (v[i] > mxv1) {
                    mx1 = i;
                    mxv1 = v[i];
                }
            }
            for (int i = 0; i < 4; i++) {
                if (v[i] > mxv2 && i != mx1) {
                    mx2 = i;
                    mxv2 = v[i];
                }
            }

            ans = {mxv1, mxv2};

            return ans;
        }

        void set (int i, int v, int x, int lx, int rx) {
            if (rx - lx == 1) {
                tree[x].first = v;
                return;
            } else {
                int m = lx + (rx - lx) / 2;
                if (i < m) set (i, v, 2 * x + 1, lx, m);
                else set (i, v, 2 * x + 2, m, rx);
                tree[x] = getMax (tree[2 * x + 1].first, tree[2 * x + 1].second, tree[2 * x + 2].first, tree[2 * x + 2].second);
            }
        }

        void set (int i, int v) {
            set (i, v, 0, 0, size);
        }

        pair <int, int> result (int l, int r, int x, int lx, int rx) {
            if (lx >= r || rx <= l) {
                return {INT_MIN, INT_MIN};
            }
            if (lx >= l && rx <= r) {
                return tree[x];
            }
            int m = lx + (rx - lx) / 2;
            pair <int, int> left = result (l, r, 2 * x + 1, lx, m);
            pair <int, int> right = result (l, r, 2 * x + 2, m, rx);
            return getMax (left.first, left.second, right.first, right.second);
        }

        void result (int l, int r) {
            cout << result (l, r, 0, 0, size).first + result (l, r, 0, 0, size).second << '\n';
        }
    };

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    SegTree st;
    int n;
    cin >> n;
    st.init (n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.set (i, x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char k;
        cin >> k;
        int l, r;
        cin >> l >> r;
        l--;
        if (k == 'U') {
            st.set (l, r);
        } else {
            st.result (l, r);
        }
    }

    return 0;
}