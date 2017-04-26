#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution 
{
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) 
	{
		M = matrix.size();
		if (M == 0)
		{
			return vector<pair<int, int>>();
		}
		N = matrix[0].size();
		if (N == 0)
		{
			return vector<pair<int, int>>();
		}
		//
		board = new int*[M];
		for (int i = 0; i < M; i++)
		{
			board[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				board[i][j] = matrix[i][j];
			}
		}
		//
		bool **b1 = visit(0, 0);
		for (int k = 1; k < M; k++)
		{
			bool **temp = visit(k, 0);
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					b1[i][j] = b1[i][j] || temp[i][j];
				}
			}
			free(temp);
		}
		for (int k = 1; k < N; k++)
		{
			bool **temp = visit(0, k);
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					b1[i][j] = b1[i][j] || temp[i][j];
				}
			}
			free(temp);
		}
		bool **b2 = visit(M - 1, N - 1);
		for (int k = 0; k < M - 1; k++)
		{
			bool **temp = visit(k, N - 1);
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					b2[i][j] = b2[i][j] || temp[i][j];
				}
			}
			free(temp);
		}
		for (int k = 0; k < N - 1; k++)
		{
			bool **temp = visit(M - 1, k);
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					b2[i][j] = b2[i][j] || temp[i][j];
				}
			}
			free(temp);
		}
		//
		vector<pair<int, int>> ret;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (b1[i][j] && b2[i][j])
				{
					ret.push_back(pair<int, int>(i, j));
				}
			}
		}
		//
		for (int i = 0; i < M; i++)
		{
			delete[] board[i];
		}
		delete[] board;
		free(b1);
		free(b2);
		//
		return ret;
	}

private:
	int M;
	int N;
	int **board;
	void free(bool **temp)
	{
		for (int i = 0; i < M; i++)
		{
			delete[] temp[i];
		}
		delete[] temp;
	}
	bool isLegalPos(int m, int n)
	{
		return (m >= 0 && m < M && n >= 0 && n < N);
	}
	bool **visit(int m0, int n0)
	{
		bool **isVisited = new bool*[M];
		for (int i = 0; i < M; i++)
		{
			isVisited[i] = new bool[N];
			for (int j = 0; j < N; j++)
			{
				isVisited[i][j] = false;
			}
		}
		//
		stack<pair<int, int>> stk;
		stk.push(pair<int, int>(m0, n0));
		isVisited[m0][n0] = true;
		while (!stk.empty())
		{
			pair<int, int> curr = stk.top();
			stk.pop();
			int x = curr.first;
			int y = curr.second;
			int xn;
			int yn;
			//
			xn = x;
			yn = y - 1;
			if (isLegalPos(xn, yn) && board[xn][yn] >= board[x][y])
			{
				if (!isVisited[xn][yn])
				{
					stk.push(pair<int, int>(xn, yn));
					isVisited[xn][yn] = true;
				}
			}
			//
			xn = x;
			yn = y + 1;
			if (isLegalPos(xn, yn) && board[xn][yn] >= board[x][y])
			{
				if (!isVisited[xn][yn])
				{
					stk.push(pair<int, int>(xn, yn));
					isVisited[xn][yn] = true;
				}
			}
			//
			xn = x - 1;
			yn = y;
			if (isLegalPos(xn, yn) && board[xn][yn] >= board[x][y])
			{
				if (!isVisited[xn][yn])
				{
					stk.push(pair<int, int>(xn, yn));
					isVisited[xn][yn] = true;
				}
			}
			//
			xn = x + 1;
			yn = y;
			if (isLegalPos(xn, yn) && board[xn][yn] >= board[x][y])
			{
				if (!isVisited[xn][yn])
				{
					stk.push(pair<int, int>(xn, yn));
					isVisited[xn][yn] = true;
				}
			}
		}
		return isVisited;
	}
};