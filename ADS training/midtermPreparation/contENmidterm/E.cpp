#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void fastIO () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

signed main() {
    fastIO ();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    long long a = 1, b = 1;
    long long n;
    cin >> n;
    int i = 2;
    bool aFiled = false;
    for (i; i * i <= n; i++) {
        while (n % i == 0) {
            if (!aFiled) {
                a *= i;
            } else {
                b *= i;
            }
            n /= i;
        }
        aFiled = true;
    }
    if (n > 1) {
        if (!aFiled) {
            a *= n;
        } else {
            b *= n;
        }
    }
    if (a == 1 || b == 1) {
        cout << -1;
    } else {
        cout << a << ' ' << b;
    }

    return 0;
}