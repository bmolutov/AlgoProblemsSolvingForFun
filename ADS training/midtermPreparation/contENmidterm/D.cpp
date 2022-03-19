#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = 1e5+5;
bool comp[N];

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    comp[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (!comp[i]) {
            for (int j = i * i; j <= n; j += i) {
                comp[j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (!comp[j] && i + j == n) {
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}