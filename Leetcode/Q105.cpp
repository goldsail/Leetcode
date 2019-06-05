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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndexMap.clear();
        for (auto it = inorder.begin(); it != inorder.end(); it++) {
            inorderIndexMap[*it] = it;
        }
        //
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    unordered_map<int, vector<int>::iterator> inorderIndexMap;
    
    TreeNode* buildTree(vector<int>::iterator preBegin, vector<int>::iterator preEnd, 
                        vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
        
        if (preBegin == preEnd) return nullptr;
        
        int parent = *preBegin;
        vector<int>::iterator it = inorderIndexMap[parent];
        TreeNode *node = new TreeNode(parent);
        
        node->left = buildTree(preBegin + 1, preBegin + 1 + (it - inBegin), 
                              inBegin, it);
        node->right = buildTree(preEnd - (inEnd - it - 1), preEnd, 
                               it + 1, inEnd);
        
        return node;
    }
};