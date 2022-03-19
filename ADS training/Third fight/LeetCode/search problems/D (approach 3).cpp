link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> answer;
        int n = (int) nums1.size ();
        sort (nums1.begin (), nums1.end ());
        for (auto num: nums2) {
            if (found (nums1, n, num) && !found (answer, (int) answer.size (), num)) {
                answer.push_back (num);
                sort (answer.begin (), answer.end ());
            }
        }
        return answer;
    }
    bool found (vector <int> & a, int n, int x) {
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] == x) {
                return true;
            }
            else if (a[m] < x) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return false;
    }
};