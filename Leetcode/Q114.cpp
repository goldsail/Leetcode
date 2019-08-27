/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flatten_(root);
    }
    
private:
    TreeNode* flatten_(TreeNode* curr) {
        if (curr == nullptr) return nullptr;
        TreeNode* left = curr->left;
        TreeNode* right = curr->right;
        curr->left = nullptr;
        if (left == nullptr) {
            if (right == nullptr) {
                return curr;
            } else {
                TreeNode* right_back = flatten_(right);
                curr->right = right;
                return right_back;
            }
        } else {
            if (right == nullptr) {
                TreeNode* left_back = flatten_(left);
                curr->left = nullptr;
                curr->right = left;
                return left_back;
            } else {
                TreeNode* left_back = flatten_(left);
                TreeNode* right_back = flatten_(right);
                curr->left = nullptr;
                curr->right = left;
                left_back->right = right;
                return right_back;
            }
        }
    }
};
