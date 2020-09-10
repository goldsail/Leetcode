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
    bool checkEqualTree(TreeNode* root) {
        count = unordered_map<TreeNode*, int>();
        if (root == nullptr) return false;
        visit(root);
        int total = count[root];
        
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->first != root && it->second * 2 == total) return true;
        }
        return false;
    }
    
private:
    unordered_map<TreeNode*, int> count;
    int visit(TreeNode* curr) {
        if (curr == nullptr) return 0;
        int result = curr->val + visit(curr->left) + visit(curr->right);
        count[curr] = result;
        return result;
    }
};
