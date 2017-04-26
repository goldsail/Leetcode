#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
	stack<char> S;

public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> ret;
		if (digits.length() > 0)
		{
			_fun(ret, digits, 0);
		}
		return ret;
	}

	void _fun(vector<string> &ret, const string &str, int pos)
	{
		if (pos == str.length())
		{
			stack<char> S2 = S;
			int n = S2.size();
			char *temp = new char[n + 1];
			temp[n] = '\0';
			for (int i = 0; i < n; i++)
			{
				temp[n - 1 -i] = S2.top();
				S2.pop();
			}
			string tmp(temp);
			ret.push_back(tmp);
			delete[] temp;
		}
		else
		{
			char temp = str[pos];
			switch (temp)
			{
			case '2':
				S.push('a');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('b');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('c');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '3':
				S.push('d');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('e');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('f');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '4':
				S.push('g');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('h');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('i');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '5':
				S.push('j');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('k');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('l');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '6':
				S.push('m');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('n');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('o');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '7':
				S.push('p');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('q');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('r');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('s');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '8':
				S.push('t');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('u');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('v');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			case '9':
				S.push('w');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('x');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('y');
				_fun(ret, str, pos + 1);
				S.pop();
				S.push('z');
				_fun(ret, str, pos + 1);
				S.pop();
				break;
			default:
				break;
			}
		}
	}
};