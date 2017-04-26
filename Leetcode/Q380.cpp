#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

class RandomizedSet 
{
public:
	/** Initialize your data structure here. */
	RandomizedSet() 
	{

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) 
	{
		bool ret = (map.find(val) == map.end());

		if (ret)
		{
			map[val] = nums.size();
			nums.push_back(val);
		}

		return ret;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{
		bool ret = (map.find(val) != map.end());

		if (ret)
		{
			int pos = map[val];

			nums[pos] = nums.back();
			map[nums.back()] = pos;

			nums.pop_back();
			map.erase(val);
		}
		
		return ret;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		return nums[rand() % nums.size()];
	}

private:
	vector<int> nums;
	unordered_map<int, int> map;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/