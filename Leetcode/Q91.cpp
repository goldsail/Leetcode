#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
	int numDecodings(string s) 
	{
		const char *str = s.c_str();
		int len = s.size();
		if (len > 0)
		{
			return _num(str, len);
		}
		else
		{
			return 0;
		}
	}

	int _num(const char *str, int len)
	{
		if (len == 0)
		{
			return 1;
		}
		if (len == 1)
		{
			return (str[0] != '0');
		}
		//
		int mid = len / 2;
		int tmid = 10 * (str[mid - 1] - '0') + (str[mid] - '0');
		int sub1 = _num(str, mid) * _num(str + mid, len - mid);
		int sub2 = _num(str, mid - 1) * _num(str + mid + 1, len - mid - 1);
		// cout << tmid << endl;
		if (tmid >= 10 && tmid <= 26)
		{
			return sub1 + sub2;
		}
		else
		{
			return sub1;
		}
	}
};