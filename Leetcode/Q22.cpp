#include <string>
#include <vector>

using namespace std;

class Solution 
{
	void recurr(char *str, int *length, vector<string> &ret, int n1, int n2)
	{
		if (n2 > 0)
		{
			if (n1 > 0)
			{
				str[*length] = ')';
				(*length)++;
				recurr(str, length, ret, n1 - 1, n2);
				(*length)--;
			}
			str[*length] = '(';
			(*length)++;
			recurr(str, length, ret, n1 + 1, n2 - 1);
			(*length)--;
		}
		else
		{
			for (int i = 0; i < n1; i++)
			{
				str[*length] = ')';
				(*length)++;
			}
			string temp = string(str, *length);
			ret.push_back(temp);
			(*length) -= n1;
		}
	}

	

public:
	vector<string> generateParenthesis(int n) 
	{
		int n1 = 0; // number of left brackets in the stack
		int n2 = n; // left bracket to insert
		char *str = new char[2 * n];
		int length = 0;
		vector<string> ret;

		recurr(str, &length, ret, n1, n2);

		delete[] str;
		return ret;
	}
};