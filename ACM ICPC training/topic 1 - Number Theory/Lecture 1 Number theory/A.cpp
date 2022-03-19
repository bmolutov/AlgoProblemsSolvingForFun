#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(temp) (int)(temp).size()
#define all(temp) (temp).begin(),(temp).end()
#define rall(temp) (temp).end(),(temp).begin()
#define fi first
#define se second
#define NFS_ ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int,int> mpii;
typedef set<int> sti;
typedef multiset<int> msti;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;

signed main() {
	NFS_
	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif
	int n;
    cin >> n;
    string ans = "";
    mpii mp_;
    int i;
    for (i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            mp_[i]++;
        }
    }
    if (n > 1) {
        mp_[n]++;
    }
    for (auto it_ = mp_.begin(); it_ != mp_.end(); ++it_) {
        ans += to_string(it_->fi);
        if (it_->se > 1) {
            ans += '^';
            ans += to_string(it_->se);
        }
        ans += '*';
    }
    ans.pop_back();
    cout << ans;
	return 0;
}