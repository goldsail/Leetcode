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
    bool isUnivalTree(TreeNode* root) {
        return (root == NULL) || (
            (root->left == NULL || 
             (root->val == root->left->val && isUnivalTree(root->left))) &&
            (root->right == NULL || 
             (root->val == root->right->val && isUnivalTree(root->right))));
    }
};
