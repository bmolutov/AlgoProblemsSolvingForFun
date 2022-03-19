link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (find (letters.begin (), letters.end (), target) == letters.end ()) {
            letters.push_back (target);
            sort (letters.begin (), letters.end ());   
        }
        vector <int> temp;
        for (int i = 0; i < (int) letters.size (); i++) {
            if (find (temp.begin (), temp.end (), letters[i]) == temp.end ()) {
                temp.push_back (letters[i]);
            }
        }
        int n = (int) temp.size ();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (temp[m] == target) {
                return temp[m + 1];
            }
            else if (temp[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        if (r == n - 1) {
            return temp[0];
        } else {
            return temp[r + 1];
        }
    }
};