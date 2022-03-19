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

using namespace std;

// commonly used data types
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;

// commonly used methods
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define sz(temp) (int)(temp).size()
#define all(temp) (temp).begin(),(temp).end()
#define rall(temp) (temp).end(),(temp).begin()
#define fi first
#define se second

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
typedef set<int> sti;
typedef set<ll> stl;
typedef multiset<int> msti;
typedef multiset<ll> mstl;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(nullptr);

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
	BOOST
	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    cout << solve(n);
	return 0;
}