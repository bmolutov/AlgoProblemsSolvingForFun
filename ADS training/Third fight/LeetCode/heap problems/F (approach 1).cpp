link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = (int) nums.size ();
        vector <bool> used (n, 0);
        int mx = INT_MIN;
        for (int i = 0; i < k; i++) {
            int mxi; mx = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (!used[j] && nums[j] > mx) {
                    mx = nums[j];
                    mxi = j;
                }
            }
            used[mxi] = true;
        }
        return mx;
    }
};