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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return s == nullptr;
        if (s == nullptr) return false;
        if (s->val == t->val) {
            if (isSametree(s->left, t->left) && isSametree(s->right, t->right))
                return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
private:
    bool isSametree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return s == nullptr;
        if (s == nullptr) return false;
        return s->val == t->val && 
            isSametree(s->left, t->left) && 
            isSametree(s->right, t->right);
    }
};
