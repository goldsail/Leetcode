#include<string>
#include<vector>

using namespace std;

class Solution 
{
public:
	vector<vector<string>> solveNQueens(int n) 
	{
		vector<vector<string>> ret;
		vector<string> board = vector<string>(n, string(n, '.'));
		_solve(0, n, ret, board);
		return ret;
	}

private:
	static void _solve(int row, int N, vector<vector<string>> &ret, vector<string> &board)
	{
		if (row == N)
		{
			ret.push_back(board);
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (_check(row, i, N, board))
				{
					board[row][i] = 'Q';
					_solve(row + 1, N, ret, board);
					board[row][i] = '.';
				}
			}
		}
	}

	static bool _check(int row, int col, int N, const vector<string> &board)
	{
		for (int i = 0; i < N; i++)
		{
			if (i != col)
			{
				if (board[row][i] == 'Q')
				{
					return false;
				}
			}
		}
		//
		for (int i = 0; i < N; i++)
		{
			if (i != row)
			{
				if (board[i][col] == 'Q')
				{
					return false;
				}
			}
		}
		//
		for (int i = 0; i < N; i++)
		{
			int j = col + (i - row);
			if (i != row && j >= 0 && j < N)
			{
				if (board[i][j] == 'Q')
				{
					return false;
				}
			}
		}
		//
		for (int i = 0; i < N; i++)
		{
			int j = col - (i - row);
			if (i != row && j >= 0 && j < N)
			{
				if (board[i][j] == 'Q')
				{
					return false;
				}
			}
		}
		//
		return true;
	}
};