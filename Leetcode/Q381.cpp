#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;


class RandomizedCollection 
{
public:
	/** Initialize your data structure here. */
	RandomizedCollection() 
	{
		
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) 
	{
		bool ret = (map.find(val) == map.end());

		elements.push_back(pair<int, int>(val, map[val].size()));
		map[val].push_back(elements.size() - 1);

		return ret;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val)
	{
		bool ret = (map.find(val) != map.end());

		if (ret)
		{
			pair<int, int> last = elements.back();
			map[last.first][last.second] = map[val].back();
			elements[map[val].back()] = last;
			map[val].pop_back();
			if (map[val].empty())
			{
				map.erase(val);
			}
			elements.pop_back();
		}

		return ret;
	}

	/** Get a random element from the collection. */
	int getRandom() 
	{
		int pos = rand() % elements.size();
		return (elements[pos].first);
	}

private:
	vector<pair<int, int>> elements;
	unordered_map<int, vector<int>> map;
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/