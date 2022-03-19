#include <bits/stdc++.h>
using namespace std;

string is_prime (int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return "composite";
        }
    }
    return "prime";
}

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    int n;
    cin >> n;
    cout << is_prime (n) << '\n';
    return 0;
}