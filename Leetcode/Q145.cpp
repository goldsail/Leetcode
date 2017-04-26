#include <vector>
#include <stack>

using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> ret;
		stack<int> temp;
		stack<TreeNode*> stk;

		stk.push(root);
		while (!stk.empty())
		{
			TreeNode *curr = stk.top();
			stk.pop();
			if (curr)
			{
				temp.push(curr->val);
				stk.push(curr->left);
				stk.push(curr->right);
			}
		}

		while (!temp.empty())
		{
			ret.push_back(temp.top());
			temp.pop();
		}

		return ret;
	}
};