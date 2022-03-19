// link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if ((int) nums.size () == 0) {
            return nullptr;
        }   
        if ((int) nums.size () == 1) {
            return new TreeNode (nums[0]);
        }
        int middle = nums.size () / 2;
        TreeNode * root = new TreeNode (nums[middle]);
        vector <int> left (nums.begin (), nums.begin () + middle);
        vector <int> right (nums.begin () + middle + 1, nums.end ());
        root -> left = sortedArrayToBST (left);
        root -> right = sortedArrayToBST (right);
        return root;
    }
};