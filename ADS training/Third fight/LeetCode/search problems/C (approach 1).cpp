link: https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        for (int i = 0; i < 100; i++) {
            int m = l + (r - l) / 2;
            if (isBadVersion (m)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }
};