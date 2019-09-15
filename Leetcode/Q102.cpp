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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        //
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 1));
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            if (curr.second == result.size()) {
                result.back().push_back(curr.first->val);
            } else {
                result.push_back(vector<int>{curr.first->val});
            }
            if (curr.first->left != nullptr) {
                que.push(make_pair(curr.first->left, curr.second + 1));
            }
            if (curr.first->right != nullptr) {
                que.push(make_pair(curr.first->right, curr.second + 1));
            }
        }
        return result;
    }
};

