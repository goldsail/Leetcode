/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) return nullptr;
        TreeNode *curr = new TreeNode(root->val);
        vector<TreeNode**> children = spawnNext(curr, root->children.size());
        for (int i = 0; i < min(children.size(), root->children.size()); i++) {
            *(children[i]) = encode(root->children[i]);
        }
        return curr;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) return nullptr;
        Node *curr = new Node(root->val);
        vector<TreeNode*> children = iterateNext(root);
        int pos = children.size();
        while (pos > 0 && children[pos - 1] == nullptr) {
            pos--;
        }
        for (int i = 0; i < pos; i++) {
            curr->children.push_back(decode(children[i]));
        }
        return curr;
    }
    
private:
    const int Depth = 10; 
    
    vector<TreeNode**> spawnNext(TreeNode *root, int capacity) {
        vector<TreeNode**> result;
        vector<TreeNode*> curr = vector<TreeNode*>(capacity, nullptr);
        int depth = 0;
        for (int depth = 0; depth < Depth; depth++) {
            vector<TreeNode*> temp;
            for (int j = 0; 2 * j < max(1, int(curr.size())); j++) {
                temp.push_back(new TreeNode(0));
                int l = 2 * j;
                temp[j]->left = (l < curr.size()) ? curr[l] : nullptr;
                if (depth == 0 && l < curr.size()) 
                    result.push_back(&temp[j]->left);
                int r = 2 * j + 1;
                temp[j]->right = (r < curr.size()) ? curr[r] : nullptr;
                if (depth == 0 && r < curr.size()) 
                    result.push_back(&temp[j]->right);
            }
            curr = temp;
        }
        root->left = curr[0]->left;
        root->right = curr[0]->right;
        return result;
    }
    
    vector<TreeNode*> iterateNext(TreeNode *root) {
        vector<TreeNode*> result;
        queue<pair<TreeNode*, int>> openSet;
        openSet.push(make_pair(root, 1));
        while (!openSet.empty()) {
            auto curr = openSet.front();
            openSet.pop();
            if (curr.second == Depth) {
                result.push_back(curr.first->left);
                result.push_back(curr.first->right);
            } else {
                if (curr.first->left != nullptr) {
                    openSet.push(make_pair(curr.first->left, curr.second + 1));
                }
                if (curr.first->right != nullptr) {
                    openSet.push(make_pair(curr.first->right, curr.second + 1));
                }
            }
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
