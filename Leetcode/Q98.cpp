#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution 
{
public:
	bool isValidBST(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return true;
		}
		if (root->left != nullptr)
		{
			TreeNode *curr = root->left;
			while (curr->right != nullptr)
			{
				curr = curr->right;
			}
			if (curr->val >= root->val)
			{
				return false;
			}
		}
		if (root->right != nullptr)
		{
			TreeNode *curr = root->right;
			while (curr->left != nullptr)
			{
				curr = curr->left;
			}
			if (curr->val <= root->val)
			{
				return false;
			}
		}
		return isValidBST(root->left) && isValidBST(root->right);
	}
};