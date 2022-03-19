#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int N = 3e5+5;
bool comp[N];

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    for (int i = 2; i * i <= N; i++) {
        if (!comp[i]) {
            for (int j = i * i; j <= N; j += i) {
                comp[j] = true;
            }
        }
    }
    int primes[n];
    int j = 2;
    for (int i = 0; i < n; i++) {
        for (j; j < N; j++) {
            if (!comp[j]) {
                comp[j] = true;
                primes[i] = j;
                break;
            }
        }
    }

    bool check[n];
    for (int i = 0; i < n - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            check[i] = true;
            check[i + 1] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}