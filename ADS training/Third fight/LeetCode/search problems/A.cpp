link: https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = (int) nums.size ();
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return r;
    }
};