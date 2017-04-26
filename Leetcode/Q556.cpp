#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		vector<char> v = num2str(n);
		int N = v.size();
		int pos = 0;
		for (int i = N - 1; i > 0; i--)
		{
			if (v[i] > v[i - 1])
			{
				pos = i;
				break;
			}
		}
		if (pos == 0)
		{
			return -1;
		}
		else
		{
			int temp = v[pos - 1];
			int tpos = pos;
			for (int i = pos; i < N; i++)
			{
				if (v[i] > temp)
				{
					tpos = i;
				}
			}
			//
			v[pos - 1] ^= v[tpos];
			v[tpos] ^= v[pos - 1];
			v[pos - 1] ^= v[tpos];
			//
			sort<vector<char>::iterator>(v.begin() + pos, v.end());
			long ret = 0;
			for (int i = 0; i < N; i++)
			{
				ret *= 10;
				ret += (v[i] - '0');
			}
			if (ret > (long)MAX)
			{
				return -1;
			}
			else
			{
				return (int)ret;
			}
		}
	}

private:
	const int MAX = 2147483647;

	static vector<char> num2str(int n)
	{
		string temp;
		stringstream ss;
		ss << n;
		ss >> temp;
		int len = temp.length();
		const char *d = temp.data();
		vector<char> ret(len);
		for (int i = 0; i < len; i++)
		{
			ret[i] = d[i];
		}
		return ret;
	}
};
