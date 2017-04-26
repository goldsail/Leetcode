#include <string>

using namespace std;

class Solution 
{
public:
	string longestPalindrome(string s) 
	{
		int n = s.length();
		if (n == 0)
			return string("");
		else 
		{
			string ret = "";
			//
			for (int init = 0; init < n; init++)
			{
				int i;
				for (i = 1; (init - i) >= 0 && (init + i) < n; i++)
				{
					if (s[init - i] != s[init + i])
						break;
				}
				if (2 * i - 1 > ret.length())
				{
					ret = s.substr(init - i + 1, 2 * i - 1);
				}
			}
			//
			for (int init = 0; init < n - 1; init++)
			{
				int i;
				for (i = 1; (init - i + 1) >= 0 && (init + i) < n; i++)
				{
					if (s[init - i + 1] != s[init + i])
						break;
				}
				if (2 * i - 2 > ret.length())
				{
					ret = s.substr(init - i + 2, 2 * i - 2);
				}
			}
			//
			return ret;
		}
	}
};