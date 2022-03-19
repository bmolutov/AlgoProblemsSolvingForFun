// link: https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    vector <string> ans;
    vector <string> subs;
    int n = (int) s.size ();
    if (n < 10) return ans;
        
    int mx = 1;
    for (int i = 0; i + 10 - 1 < n; i++) {
        string temp = s.substr (i, 10);
        subs.push_back (temp);
        mx = max (mx, (int) temp.size ());
    }

    int p = 31;
    unsigned long long mod = ULLONG_MAX;
    unsigned long long factors[mx];
    factors[0] = 1;
    for (int i = 1; i < mx; i++) {
        factors[i] = factors[i - 1] * p;
        factors[i] %= mod;
    }

    vector <pair <unsigned long long, int>> hashes (n - 9);
    for (int i = 0; i + 10 - 1 < n; i++) {
        unsigned long long hash = 0;
        for (int j = 0; j < (int) subs[i].size (); j++) {
            hash += (subs[i][j] - 'A' + 1) * factors[j];
            hash %= mod;
        }
        hashes[i] = {hash, i};
    }
        
    sort (hashes.begin (), hashes.end ());

    int cnt = 1;
    string t = subs[hashes[0].second];

    for (int i = 1; i < (int) hashes.size ();) {
        while (subs[hashes[i].second] == t) {
            i++;
            cnt++;
            if (i >= (int) hashes.size ()) break;
        }
        if (cnt > 1) {
            if (find (ans.begin (), ans.end (), t) == ans.end ()) ans.push_back (t);
        }
        if (i >= (int) hashes.size ()) break;
        cnt = 1;
        t = subs[hashes[i].second];
        i++;
    }

    if (cnt > 1) {
        if (find (ans.begin (), ans.end (), t) == ans.end ()) ans.push_back (t);
    }
        
        return ans;
    }
};
