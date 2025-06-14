// DFS
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
    bool checkIsSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (left && right)
            return (left->val == right->val) && 
                    checkIsSymmetric(left->left, right->right) && 
                    checkIsSymmetric(left->right, right->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return checkIsSymmetric(root->left, root->right);
    }
};


// BFS
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(root->left, root->right));
        while(!q.empty()) {
            TreeNode *left = q.front().first;
            TreeNode *right = q.front().second;
            q.pop();
            if(!left && !right) {
                continue;
            } else if(!left || !right) {
                return false;
            } else if(left->val != right->val) {
                return false;
            }

            q.push(make_pair(left->right, right->left));
            q.push(make_pair(left->left, right->right));
        }
        return true;
    }
};

// syntax sugar
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while(!q.empty()) {
            TreeNode *left = q.front().first;
            TreeNode *right = q.front().second;
            q.pop();
            if(!left && !right) {
                continue;
            } else if(!left || !right) {
                return false;
            } else if(left->val != right->val) {
                return false;
            }

            q.push({left->right, right->left});
            q.push({left->left, right->right});
        }
        return true;
    }
};
