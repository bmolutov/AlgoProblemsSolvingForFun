link: https://leetcode.com/problems/guess-number-higher-or-lower/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = -1, r = n;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (guess (m) == 0) {
                return m;
            } else if (guess (m) == 1) {
                l = m;
            }
            else if (guess (m) == -1) {
                r = m;
            }
        }
        return n;
    }
};