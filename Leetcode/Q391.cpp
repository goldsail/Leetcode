#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution 
{
public:
	bool isRectangleCover(vector<vector<int>> &rectangles)
	{
		int n = rectangles.size();
		int *arr = new int[4*n];
		for (int i = 0; i < 4 * n; i += 4)
		{
			arr[i + 0] = rectangles[i / 4][0];
			arr[i + 1] = rectangles[i / 4][1];
			arr[i + 2] = rectangles[i / 4][2];
			arr[i + 3] = rectangles[i / 4][3];
		}
		return _isRectangleCover(arr, n);
	}

	static bool _isRectangleCover(const int *rectangles, int n) 
	{
		//
		unordered_set<int> xs;
		unordered_set<int> ys;
		for (int i = 0; i < 4*n; i+=4)
		{
			_set_insert(xs, rectangles[i+0]);
			_set_insert(ys, rectangles[i+1]);
			_set_insert(xs, rectangles[i+2]);
			_set_insert(ys, rectangles[i+3]);
		}
		//
		int _i;
		vector<int> xv = vector<int>(xs.size());
		vector<int> yv = vector<int>(ys.size());
		_i = 0;
		for (auto iter = xs.begin(); iter != xs.end(); iter++)
		{
			xv[_i++] = *iter;
		}
		_i = 0;
		for (auto iter = ys.begin(); iter != ys.end(); iter++)
		{
			yv[_i++] = *iter;
		}
		sort<vector<int>::iterator>(xv.begin(), xv.end());
		sort<vector<int>::iterator>(yv.begin(), yv.end());
		//
		unordered_map<int, int> xm;
		unordered_map<int, int> ym;
		int xn = 0;
		int yn = 0;
		for (auto iter = xv.begin(); iter != xv.end(); iter++)
		{
			xm[*iter] = xn;
			xn++;
		}
		for (auto iter = yv.begin(); iter != yv.end(); iter++)
		{
			ym[*iter] = yn;
			yn++;
		}
		//
		int *recs = new int[4 * n];
		for (int i = 0; i < 4 * n; i += 4)
		{
			recs[i + 0] = xm[rectangles[i + 0]];
			recs[i + 1] = ym[rectangles[i + 1]];
			recs[i + 2] = xm[rectangles[i + 2]];
			recs[i + 3] = ym[rectangles[i + 3]];
		}

		//
		// size: (xn-1)-by-(yn-1)
		bool **board = new bool*[xn - 1];
		for (int i = 0; i < xn - 1; i++)
		{
			board[i] = new bool[yn - 1];
			for (int j = 0; j < yn - 1; j++)
			{
				board[i][j] = false;
			}
		}
		cout << "s1" << endl;
		//
		for (int c = 0; c < 4*n; c+=4)
		{
			int x0 = recs[c+0];
			int y0 = recs[c+1];
			int x1 = recs[c+2];
			int y1 = recs[c+3];
			//
			for (int i = x0; i < x1; i++)
			{
				for (int j = y0; j < y1; j++)
				{
					if (board[i][j])
					{
						return false;
					}
					board[i][j] = true;
				}
			}
		}
		//
		for (int i = 0; i < xn - 1; i++)
		{
			for (int j = 0; j < yn - 1; j++)
			{
				if (!board[i][j])
				{
					return false;
				}
			}
		}
		//
		return true;
	}

private:
	static void _set_insert(unordered_set<int> &s, int x)
	{
		if (s.find(x) == s.end())
		{
			s.insert(x);
		}
	}
};


#include <fstream>
#include <iostream>
int main()
{
	ifstream file = ifstream("C:/Users/Fan/Desktop/test2.txt");
	vector<vector<int>> recs;
	while (!file.eof())
	{
		vector<int> temp;
		for (int i = 0; i < 4; i++)
		{
			int tmp;
			file >> tmp;
			temp.push_back(tmp);
		}
		recs.push_back(temp);
	}
	Solution solu;
	cout << "s0" << endl;
	cout << solu.isRectangleCover(recs) << endl;
	return 0;
}