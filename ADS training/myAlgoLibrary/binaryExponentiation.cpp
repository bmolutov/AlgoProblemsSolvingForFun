#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

 ull fastPow (ull a, ull b) {
     if (b == 0) return 1;
     if (b % 2 == 0) return fastPow ((a * a), b / 2);
     if (b % 2 == 1) return a * fastPow (a, b - 1);
 }

void solve () {
    ull a, b;
    cin >> a >> b;
    cout << fastPow (a, b);
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