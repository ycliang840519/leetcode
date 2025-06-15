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
    TreeNode* arrayToBST(vector<int>& nums, int lIndex, int rIndex) {
        if (lIndex > rIndex)
            return NULL;
        int m = (rIndex - lIndex)/2 + lIndex;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = arrayToBST(nums, lIndex, m - 1);
        root->right = arrayToBST(nums, m + 1, rIndex);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size() - 1);
    }
};
