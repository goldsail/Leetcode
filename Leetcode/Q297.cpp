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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        serialize(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string::iterator iter = data.begin();
        return deserialize(iter, data.end());
    }
    
private:
    void serialize(TreeNode* curr, string& str) {
        str.push_back('{');
        if (curr == nullptr) {
            str.push_back('n');
        } else {
            serialize(curr->left, str);
            str += to_string(curr->val);
            serialize(curr->right, str);
        }
        str.push_back('}');
    }
    
    TreeNode* deserialize(string::iterator &curr, string::iterator end) {
        if (curr[1] == 'n') {
            curr += 3;
            return nullptr;
        }
        curr += 1; // skip '{'
        TreeNode* left = deserialize(curr, end);
        bool neg = false;
        if (curr[0] == '-') {
            neg = true;
            curr++;
        }
        int val = 0;
        while (curr[0] >= '0' && curr[0] <= '9') {
            val = 10 * val + (curr[0] - '0');
            curr++;
        }
        if (neg) val *= (-1);
        TreeNode* node = new TreeNode(val);
        TreeNode* right = deserialize(curr, end);
        curr += 1; // skip '}'
        //
        node->left = left;
        node->right = right;
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
