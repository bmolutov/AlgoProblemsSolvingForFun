// link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
class Solution {
public:
    vector <int> v;
    bool findTarget(TreeNode* root, int k) {
        traverse (root);
        int i = 0, j = (int) v.size () - 1;
        while (i < j) {
            if (v[i] + v[j] == k) return true;
            (v[i] + v[j] < k) ? i++ : j--;
        }
        return false;
    }
    void traverse (TreeNode * root) {
        if (root != nullptr) {
            traverse (root -> left);
            v.push_back (root -> val);
            traverse (root -> right);
        }
    }
};