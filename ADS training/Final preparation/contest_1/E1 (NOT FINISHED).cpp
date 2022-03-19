#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        vector <int> temp;
        int t = i;
        for (int j = 2; j <= t; j++) {
            while (t % j == 0 && t > 1) {
                t /= j;
                temp.push_back (j);
            }
        }
        bool flag = false;
        for (int j = 0; j < (int) temp.size () - 1; j++) {
            if (temp[j] == temp[j + 1]) {
                flag = true;
                break;
            }
        }
        if (((int) temp.size () == 3 && flag) || ((int) temp.size () >= 3 && !flag) || (int) temp.size () == 1) {
            cnt++;
        } else {
//            cout << "I: " << i << '\n';
        }
    }
    cout << n - cnt;
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