#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int count[128];
		int n = s.length();
		char *str = new char[n + 1];
		str[n] = '\0';
		for (int i = 0; i < n; i++)
			str[i] = s[i];
		int max = 0;
		for (int j = 0; j < 128; j++)
			count[j] = 0;
		int curr_prev = 0;
		for (int i = 0; i < n; i++)
		{
			int curr = curr_prev;
			while (curr < n && count[str[curr]] == 0)
			{
				count[str[curr]]++;
				curr++;
			}
			count[str[i]]--;
			curr_prev = curr;
			if (max < curr - i)
				max = curr - i;
		}
		delete[] str;
		return max;
	}
};

