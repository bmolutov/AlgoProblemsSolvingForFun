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
        for (int i = 0; i < (int) v.size () - 1; i++) {
            for (int j = i + 1; j < (int) v.size (); j++) {
                if (v[i] + v[j] == k) {
                    return true;
                }
            }
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