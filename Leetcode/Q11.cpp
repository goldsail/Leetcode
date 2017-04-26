#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxArea(vector<int>& height) 
	{
		int len = height.size();
		int *arr = new int[len];
		for (int i = 0; i < len; i++)
			arr[i] = height[i];
		int ret = _maxArea((const int*)arr, len);
		delete[] arr;
		return ret;
	}

private:
	struct Node
	{
		int h;
		int w;
	};

	static int _cmp(const void *a, const void *b)
	{
		Node *pa = (Node*)a;
		Node *pb = (Node*)b;
		return (pb->h - pa->h);
	}

	int _find(const Node *arr, int left, int right, int target)
	{
		if (right - left < 5)
		{
			for (int i = left; i < right; i++)
			{
				if (arr[i].h >= target)
				{
					return i;
				}
			}
			return -1;
		}
		else
		{
			int mid = (left + right) / 2 ;
			if (arr[mid].h < target)
			{
				return _find(arr, mid, right, target);
			}
			else if (arr[mid].h > target)
			{
				int temp = _find(arr, left, mid, target);
				if (temp < 0)
					return mid;
				else
					return temp;
			}
			else
			{
				return mid;
			}
		}
	}

	int _maxArea(const int *arr, int len)
	{
		int ret = 0;
		if (len < 5)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < i; j++)
				{
					int min = (arr[i] < arr[j]) ? arr[i] : arr[j];
					if (ret < (i - j) * min)
					{
						ret = (i - j) * min;
					}
				}
			}
		}
		else
		{
			int mid = len / 2;
			int t1 = _maxArea(arr, mid);
			int t2 = _maxArea(arr + mid, len - mid);
			int t3 = 0;
			//
			Node *pleft = new Node[len];
			int nleft = 0;
			for (int i = mid - 1; i >= 0; i--)
			{
				Node temp;
				temp.h = arr[i];
				temp.w = (mid - 1 - i);
				pleft[nleft] = temp;
				nleft++;
			}
			qsort((void*)pleft, nleft, sizeof(Node), _cmp);
			//
			Node *pright = new Node[len];
			int nright = 0;
			for (int i = mid; i < len; i++)
			{
				Node temp;
				temp.h = arr[i];
				temp.w = (i - mid);
				pright[nright] = temp;
				nright++;
			}
			qsort((void*)pright, nright, sizeof(Node), _cmp);
			//
			Node *tleft = new Node[nleft];
			int cleft = 0;
			for (int i = 0; i < nleft; i++)
			{
				if (cleft == 0 || pleft[i].w > tleft[cleft - 1].w)
				{
					if (cleft != 0 && pleft[i].h == tleft[cleft - 1].h)
					{
						cleft--;
					}
					tleft[cleft] = pleft[i];
					cleft++;
				}
			}
			Node *tright = new Node[nright];
			int cright = 0;
			for (int i = 0; i < nright; i++)
			{
				if (cright == 0 || pright[i].w > tright[cright - 1].w)
				{
					if (cright != 0 && pright[i].h == tright[cright - 1].h)
					{
						cright--;
					}
					tright[cright] = pright[i];
					cright++;
				}
			}
			//
			Node *aleft = new Node[cleft];
			for (int i = 0; i < cleft; i++)
			{
				aleft[cleft - 1 - i] = tleft[i];
			}
			for (int i = 0; i < cright; i++)
			{
				int pos = _find(aleft, 0, cleft, tright[i].h);
				if (pos >= 0)
				{
					int r = tright[i].h * (tright[i].w + 1 + aleft[pos].w);
					if (r > t3)
					{
						t3 = r;
					}
				}
			}
			//
			Node *aright = new Node[cright];
			for (int i = 0; i < cright; i++)
			{
				aright[cright - 1 - i] = tright[i];
			}
			for (int i = 0; i <cleft; i++)
			{
				int pos = _find(aright, 0, cright, tleft[i].h);
				if (pos >= 0)
				{
					int r = tleft[i].h * (tleft[i].w + 1 + aright[pos].w);
					if (r > t3)
					{
						t3 = r;
					}
				}
			}

			//
			if (t1 > ret)
			{
				ret = t1;
			}
			if (t2 > ret)
			{
				ret = t2;
			}
			if (t3 > ret)
			{
				ret = t3;
			}
		}
		//
		return ret;
	}
};


