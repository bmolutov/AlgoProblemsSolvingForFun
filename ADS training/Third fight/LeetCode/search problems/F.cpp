link: https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int n = num;
        double l = 0, r = (double) n;
        for (int i = 0; i < 100; i++) {
            double m = l + (r - l) / 2;
            if (m * m < n) {
                l = m;
            }
            else {
                r = m;
            }
        }
        int temp = (int) r;
        if (n == temp * temp) {
            return true;
        }
        else {
            return false;
        }
    }
};