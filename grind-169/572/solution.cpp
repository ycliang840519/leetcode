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
    bool isSameTree(TreeNode* r, TreeNode* s) {
        if(!r && !s) {
            return true;
        } else if(r && s) {
            if(r->val == s->val) {
                return isSameTree(r->left, s->left) && isSameTree(r->right, s->right);
            }
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root && !subRoot)
            return true;
        else if (!root && subRoot)
            return false;
        else 
            return isSameTree(root, subRoot) || 
                   isSubtree(root->left, subRoot) || 
                   isSubtree(root->right, subRoot);
    }
};
