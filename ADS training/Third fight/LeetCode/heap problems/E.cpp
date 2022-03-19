link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        for (int i = 0; i < (int) nums.size (); i++) {
            for (int j = 0; j < (int) nums.size (); j++) {
                if (i != j) {
                    int target = (nums[i] - 1) * (nums[j] - 1);
                    if (target > mx) {
                        mx = target;
                    }
                }
            }
        }
        return mx;
    }
};