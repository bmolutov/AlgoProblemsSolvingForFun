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

str solve (ll n) {
    str ans;
    while (n % 2 == 0) {
        ans += "2*";
        n /= 2;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            ans += to_string(d) + '*';
            n /= d;
        }
    }
    if (n > 1) {
        ans += to_string(n) + '*';
    }
    ans.ppb();
    return ans;
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    cout << solve (n);

    return 0;
}