link: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        double l = 0, r = x, m;
        for (int i = 0; i < 100; i++) {
            m = l + (r - l) / 2;
            if (m * m < x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return (int) r;
    }
};