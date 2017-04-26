#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	int countBattleships(vector<vector<char>>& board) 
	{
		M = board.size();
		if (M == 0)
		{
			return 0;
		}
		N = board[0].size();
		if (N == 0)
		{
			return 0;
		}
		return _count(board, 0, 0, M, N);
	}

private:

	int M;
	int N;

	bool isLegalPos(int m, int n)
	{
		return (m >= 0 && m < M) && (n >= 0 && n < N);
	}

	int _count(vector<vector<char>> &board, int r, int c, int m, int n)
	{
		if (r == 1 && c == 2 && m == 2 && n == 2)
		{
			int x = 0;
		}
		if (m == 0 || n == 0)
		{
			return 0;
		}
		if (m == 1 && n == 1)
		{
			// cout << r << ' ' << c << ' ' << m << ' ' << n << ' ' << ((board[r][c] == 'X') ? 1 : 0) << endl;
			return (board[r][c] == 'X') ? 1 : 0;
		}
		//
		int ret = 0;
		if (m >= n)
		{
			int mid = m / 2;
			ret += _count(board, r, c, mid, n);
			ret += _count(board, r + mid, c, m - mid, n);
			for (int i = 0; i < n; i++)
			{
				if (board[r + mid - 1][c + i] == 'X')
				{
					if (board[r + mid][c + i] == 'X')
					{
						ret--;
					}
				}
			}
		}
		else
		{
			int mid = n / 2;
			ret += _count(board, r, c, m, mid);
			ret += _count(board, r, c + mid, m, n - mid);
			for (int i = 0; i < m; i++)
			{
				if (board[r + i][c + mid - 1] == 'X')
				{
					if (board[r + i][c + mid] == 'X')
					{
						ret--;
					}
				}
			}
		}
		// cout << r << ' ' << c << ' ' << m << ' ' << n << ' ' << ret << endl;
		return ret;
	}
};
