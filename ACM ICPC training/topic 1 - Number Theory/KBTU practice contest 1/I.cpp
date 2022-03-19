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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

lld dist (lld x1, lld y1, lld x2, lld y2) {
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector <pair<pair<int, int>, int>> v;
    set <pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        v.push_back({{x, y}, r});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = v[i].ff.ff, y1 = v[i].ff.ss;
            int x2 = v[j].ff.ff, y2 = v[j].ff.ss;
            int r1 = v[i].ss, r2 = v[j].ss;
            if (dist(x1, y1, x2, y2) == r1 + r2) {
                s.insert ({min(i+1, j+1), max(i+1, j+1)});
            }
        }
    }
    for (auto i: s) {
        cout << i.ff << ' ' << i.ss << endl;
    }
    return 0;
}