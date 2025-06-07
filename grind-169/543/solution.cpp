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
    int diameterOfBinaryTree(TreeNode* root) {
        longestPathToLeaf(root);
        return diameter - 1;    // return the edge count (diameter is number of nodes)
    }

    // longest path: the maximum number of node a root to its leaf contains
    int longestPathToLeaf(TreeNode* root) {  
        if (root == NULL)
            return 0;
        int maxLeftDepth = longestPathToLeaf(root->left);
        int maxRightDepth = longestPathToLeaf(root->right);

        diameter = max(diameter, maxLeftDepth + maxRightDepth + 1); // +1: plus root node itself

        return max(maxLeftDepth, maxRightDepth) + 1;
    }
private:
    int diameter = 0;
};
