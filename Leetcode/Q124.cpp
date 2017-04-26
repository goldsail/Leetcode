#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		currMax = MIN;
		if (!root)
			return MIN;
		//
		_visitMono(root);
		//
		for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
		{
			TreeNode *curr = *iter;
			if (curr->left && curr->right)
			{
				int temp = mapMono[curr->left] + mapMono[curr->right] + curr->val;
				currMax = (temp > currMax) ? temp : currMax;
			}			
			currMax = (mapMono[curr] > currMax) ? mapMono[curr] : currMax;
		}
		return currMax;
	}

private:
	unordered_set<TreeNode*> nodes;
	unordered_map<TreeNode*, int> mapMono;
	int currMax;
	const int MIN = -1e5;
	//
	int _visitMono(TreeNode *curr)
	{
		if (!curr)
		{
			return MIN;
		}
		if (nodes.find(curr) == nodes.end())
		{
			nodes.insert(curr);
		}
		int cleft = _visitMono(curr->left);
		int cright = _visitMono(curr->right);
		int temp = curr->val + ((cleft > cright) ? cleft : cright);
		temp = (curr->val > temp) ? curr->val : temp;
		mapMono[curr] = temp;
		return temp;
	}
};