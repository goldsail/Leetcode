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
private:
    enum State {
        ZERO,
        ONE,
        TWO
    };
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        //
        stack<pair<TreeNode*, State>> stk;
        stk.push(make_pair(root, ZERO));
        while (!stk.empty()) {
            switch (stk.top().second) {
                case ZERO:
                    stk.top().second = ONE;
                    if (stk.top().first->left != nullptr) {
                        stk.push(make_pair(stk.top().first->left, ZERO));
                    }
                    break;
                case ONE:
                    result.push_back(stk.top().first->val);
                    stk.top().second = TWO;
                    if (stk.top().first->right != nullptr) {
                        stk.push(make_pair(stk.top().first->right, ZERO));
                    }
                    break;
                case TWO:
                    stk.pop();
                    break;
            }
        }
        return result;
    }
};

