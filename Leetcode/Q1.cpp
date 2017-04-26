#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
	struct Node
	{
		int num;
		bool flag;
		int index;
		//
		bool operator<(const Node &rhs) const
		{
			return this->num < rhs.num;
		}
	};

	struct Node2
	{
		int num;
		bool flag;
		int index;
		//
		bool operator<(const Node2 &rhs) const
		{
			return this->flag < rhs.flag;
		}
	};

public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		vector<Node> v;
		vector<int> numsp = nums;
		for (int i = 0; i < nums.size(); i++)
		{
			numsp[i] = target - nums[i];
			Node temp;
			temp.flag = false;
			temp.num = numsp[i];
			temp.index = i;
			v.push_back(temp);
		}
		for (int i = 0; i < nums.size(); i++)
		{
			Node temp;
			temp.flag = true;
			temp.num = nums[i];
			temp.index = i;
			v.push_back(temp);
		}
		//
		sort(v.begin(), v.end());
		vector<int> pos;
		pos.push_back(0);
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].num != v[i - 1].num)
			{
				pos.push_back(i);
			}
		}
		pos.push_back(v.size());
		for (int i = 0; i < pos.size() - 1; i++)
		{
			int inf = pos[i];
			int sup = pos[i + 1];
			vector<Node2> vt;
			for (int j = inf; j < sup; j++)
			{
				Node2 tmp;
				tmp.num = v[j].num;
				tmp.index = v[j].index;
				tmp.flag = v[j].flag;
				vt.push_back(tmp);
			}
			sort(vt.begin(), vt.end());
			for (int j = 1; j < sup - inf; j++)
			{
				if (vt[j].flag != vt[j - 1].flag)
				{
					vector<int> temp;
					temp.push_back(vt[j].index);
					temp.push_back(vt[j - 1].index);
					return temp;
				}
			}
		}
		return vector<int>();
	}
};

