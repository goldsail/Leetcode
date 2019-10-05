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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            if (curr.second == result.size()) {
                result.push_back(vector<int>{});
            }
            result[curr.second].push_back(curr.first->val);
            //
            if (curr.first->left != nullptr) {
                que.push(make_pair(curr.first->left, curr.second + 1));
            }
            if (curr.first->right != nullptr) {
                que.push(make_pair(curr.first->right, curr.second + 1));
            }
        }
        //
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
