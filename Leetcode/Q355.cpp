#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

class Twitter 
{
public:
	/** Initialize your data structure here. */
	Twitter() 
	{
		timestamp = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) 
	{
		Tweets[userId].push_back(pair<int, int>(tweetId, timestamp));
		timestamp++;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) 
	{
		if (Follows[userId].find(userId) == Follows[userId].end())
		{
			Follows[userId].insert(userId);
		}
		vector<pair<int, int>> temp;
		for (auto iter = Follows[userId].begin(); iter != Follows[userId].end(); iter++)
		{
			int c = max<int>(Tweets[*iter].size() - 10, 0);
			for (int i = Tweets[*iter].size() - 1; i >= c; i--)
			{
				temp.push_back(Tweets[*iter][i]);
			}
		}
		_cmp cmp;
		sort<vector<pair<int, int>>::iterator, _cmp>(temp.begin(), temp.end(), cmp);
		int c = min<int>(temp.size(), 10);
		vector<int> ret;
		for (int i = 0; i < c; i++)
		{
			ret.push_back(temp[i].first);
		}
		return ret;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) 
	{
		if (Follows[followerId].find(followeeId) == Follows[followerId].end())
		{
			Follows[followerId].insert(followeeId);
		}
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) 
	{
		if (Follows[followerId].find(followeeId) != Follows[followerId].end())
		{
			Follows[followerId].erase(followeeId);
		}
	}

private:
	int timestamp;
	map<int, set<int>> Follows;
	map<int, vector<pair<int, int>>> Tweets;
	struct _cmp
	{
		bool operator()(const pair<int, int> &left, const pair<int, int> &right)
		{
			return left.second > right.second;
		}
	};
};
