/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// recursive: return the root node that p and q is on the different side of
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (((p->val >= root->val) && (q->val <= root->val)) || ((p->val <= root->val) && (q->val >= root->val)))
        return root;
    else if (p->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return lowestCommonAncestor(root->left, p, q);
}

// iterative: same idea, first find the leftest that have the smaller val on the left, then find the rightest that have the bigger val on the right
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int bigger = p->val, smaller = q->val;
    if (p->val < q->val) {
        bigger = q->val;
        smaller = p->val;
    }
    while (true) {
        if (root->val > bigger) {
            root = root->left;
        } else if (root->val < smaller) {
            root = root->right;
        } else {
            return root;
        }
    }
}
