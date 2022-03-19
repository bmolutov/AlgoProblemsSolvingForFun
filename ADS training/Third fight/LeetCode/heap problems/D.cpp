link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = (int) mat.size ();
        vector <bool> check (m, 0);
        vector <int> ans;
        for (int ii = 0; ii < k; ii++) {
            int mni;
            int mn = INT_MAX;
            for (int i = 0; i < m; i++) {
                if (check[i]) {
                    continue;
                }
                int sum = 0;
                int n = (int) mat[i].size ();
                for (int j = 0; j < n; j++) {
                    sum += mat[i][j];
                }
                if (sum < mn) {
                    mn = sum;
                    mni = i;
                }
            }
            ans.push_back (mni);
            check[mni] = true;
        }
        return ans;
    }
};