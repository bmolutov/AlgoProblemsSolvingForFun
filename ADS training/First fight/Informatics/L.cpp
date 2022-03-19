#include <bits/stdc++.h>
using namespace std;

long long gcd_ (long long a, long long b) {
    while (a * b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return (a + b);
}

signed main () {
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    long long a, b;
    cin >> a >> b;
    cout << (a * b) / gcd_ (a, b) << '\n';
    return 0;
}