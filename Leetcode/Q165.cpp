#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<int> v1 = cast(version1.c_str());
		vector<int> v2 = cast(version2.c_str());
		//
		int n1 = v1.size();
		int n2 = v2.size();
		//
		for (int i = 0; i < n1 - n2; i++)
		{
			v2.push_back(0);
		}
		for (int i = 0; i < n2 - n1; i++)
		{
			v1.push_back(0);
		}
		int n = v1.size();
		for (int i = 0; i < n; i++)
		{
			if (v1[i] < v2[i])
			{
				return -1;
			}
			if (v1[i] > v2[i])
			{
				return 1;
			}
		}
		return 0;
	}

private:
	vector<int> cast(const char *v)
	{
		vector<int> ret;
		const char *curr = v;
		int temp = 0;
		while (true)
		{
			if (curr[0] == '\0')
			{
				ret.push_back(temp);
				break;
			}
			else
			{
				if (curr[0] == '.')
				{
					ret.push_back(temp);
					temp = 0;
					curr++;
				}
				else
				{
					temp = 10 * temp + (curr[0] - '0');
					curr++;
				}
			}
		}
		return ret;
	}
};