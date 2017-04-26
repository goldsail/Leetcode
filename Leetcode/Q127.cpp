#include <string>
#include <set>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution 
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
	{
		set<string> list;
		for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
		{
			list.insert(*iter);
		}
		queue<pair<string, int>> que;
		set<string> rec;
		//
		que.push(pair<string, int>(beginWord, 1));
		rec.insert(beginWord);
		while (!que.empty())
		{
			pair<string, int> curr = que.front();
			que.pop();
			if (curr.first == endWord)
			{
				return curr.second;
			}
			vector<string> nexts = getNext(curr.first, list);
			for (auto iter = nexts.begin(); iter != nexts.end(); iter++)
			{
				string temp = *iter;
				if (rec.find(temp) == rec.end())
				{
					que.push(pair<string, int>(temp, curr.second + 1));
					rec.insert(temp);
				}
			}
		}
		return 0;
	}

private:
	vector<string> getNext(const string &str, const set<string> &wordlist)
	{
		vector<string> ret;
		int n = str.length();
		for (int i = 0; i < n; i++)
		{
			string temp = str;
			char ch = str[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c != ch)
				{
					temp[i] = c;
					if (wordlist.find(temp) != wordlist.end())
					{
						ret.push_back(temp);
					}
				}
			}
		}
		return ret;
	}
};