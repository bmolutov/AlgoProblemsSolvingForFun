link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> answer;
        for (auto num: nums2) {
            vector <int> :: iterator it = find (nums1.begin (), nums1.end (), num); 
            if (it != nums1.end ()) {
                answer.push_back (num);
                nums1.erase (it);
            }
        }
        return answer;
    }
};