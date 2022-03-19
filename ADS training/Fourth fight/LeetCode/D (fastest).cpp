// link: https://leetcode.com/problems/range-sum-of-bst/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

const int FASTIO = [] () {
    ios_base :: sync_with_stdio (false);
    cin.tie (nullptr);
    return 0;
} ();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int sum = rangeSumBST (root -> left, low, high) + rangeSumBST (root -> right, low, high);
        if (root -> val >= low && root -> val <= high) {
            sum += root -> val;
        }
        return sum;
    }
};