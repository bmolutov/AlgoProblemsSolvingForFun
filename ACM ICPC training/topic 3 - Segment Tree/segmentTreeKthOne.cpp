#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// commonly used data types
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef string str;

// commonly used methods
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define sz(temp) (int)(temp).size()
#define all(temp) (temp).begin(),(temp).end()
#define rall(temp) (temp).end(),(temp).begin()
#define ff first
#define ss second

//others
#define endl '\n'

// useful constants
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// vector and pair
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

// map, set, multiset
typedef map<int,int> mpii;
typedef map<ll,ll> mpll;
typedef unordered_map<int,int> umpii;
typedef unordered_map<ll,ll> umpll;
typedef set<int> sti;
typedef set<ll> stl;
typedef unordered_set<int> usti;
typedef unordered_set<ll> ustl;
typedef multiset<int> msti;
typedef multiset<ll> mstl;

// debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; print_(x); cerr << endl;
#else
#define debug(x)
#endif
void print_(ll t) {cerr << t;}
void print_(int t) {cerr << t;}
void print_(str t) {cerr << t;}
void print_(char t) {cerr << t;}
void print_(lld t) {cerr << t;}
void print_(double t) {cerr << t;}
void print_(ull t) {cerr << t;}
template <class T, class V> void print_(pair <T, V> p);
template <class T> void print_(vector <T> v);
template <class T> void print_(set <T> v);
template <class T, class V> void print_(map <T, V> v);
template <class T> void print_(multiset <T> v);
template <class T, class V> void print_(pair <T, V> p) {cerr << "{"; print_(p.ff); cerr << ","; print_(p.ss); cerr << "}";}
template <class T> void print_(vector <T> v) {cerr << "[ "; for (T i : v) {print_(i); cerr << " ";} cerr << "]";}
template <class T> void print_(set <T> v) {cerr << "[ "; for (T i : v) {print_(i); cerr << " ";} cerr << "]";}
template <class T> void print_(multiset <T> v) {cerr << "[ "; for (T i : v) {print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {print_(i); cerr << " ";} cerr << "]";}

// for basic operations
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y;}
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y;}

// optimization
void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct SegTree {
    vi tree;
    int size{};

    void build (vi & a, int x, int lx, int rx) {
        if (rx - lx  == 1) {
            if (lx < sz (a)) tree[x] = a[lx];
        }
        else {
            int m = (lx + rx) / 2;
            build (a, 2 * x + 1, lx, m);
            build (a, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void build (vi & a) {
        init (sz (a));
        build (a, 0, 0, size);
    }

    void init (int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign (2 * size - 1, 0);
    }

    void set (int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set (i, val, 2 * x + 1, lx, m);
        else set (i, val, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set (int i, int val) {
        set (i, val, 0, 0, size);
    }

    int find (int k, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (k < tree[2 * x + 1]) {
            return find (k, 2 * x + 1, lx, m);
        } else {
            return find (k - tree[2 * x + 1], 2 * x + 2, m, rx);
        }
    }

    int find (int k) {
        return find (k, 0, 0, size);
    }
};

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    

    return 0;
}