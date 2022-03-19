#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

template <typename T>
class fenwick {
    public:
    vector<T> fenw;
    int n;
 
    fenwick(int _n) : n(_n) {
      fenw.resize(n);
    }
 
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] = (fenw[x] + v) % mod;
            x |= (x + 1);
        }
    }
 
    T get(int x) {
        T v{};
        while (x >= 0) {
            v = (v + fenw[x]) % mod;
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};


signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    fenwick<int> ft(n + 1);
    ft.modify(0, 1); 
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i - k;
        dp[i] = (ft.get(i - 1) - ft.get(j - 1) + mod) % mod;
        // dp[i] += 1;
        // dp[i] %= mod;
        // ans = (ans + dp[i]) % mod;
        ft.modify(i, dp[i]); 
    }
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // cout << '\n';
    for (int i = n - k + 1; i <= n; i++) {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans;
    return 0;
}