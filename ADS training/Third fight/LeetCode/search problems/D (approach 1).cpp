link: https://leetcode.com/problems/intersection-of-two-arrays/submissions/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> answer;
        unordered_set <int> us (nums1.begin (), nums1.end ());
        for (auto i: nums2) {
            if (us.count (i)) {
                answer.push_back (i);
                us.erase (i);
            }
        }
        return answer;
    }
};