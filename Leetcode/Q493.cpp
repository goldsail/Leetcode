#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int reversePairs(vector<int>& nums) 
	{
		int n = nums.size();
		long *arr = new long[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = nums[i];
		}
		int ret = _reversePairs(arr, n);
		delete[] arr;
		return ret;
	}

private:
	static int _reversePairs(const long *arr, int n)
	{
		int count = 0;
		if (n < 5)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i < j && arr[i] > 2 * arr[j])
					{
						count++;
					}
				}
			}
			return count;
		}
		//
		int mid = n / 2;
		count += _reversePairs(arr, mid);
		count += _reversePairs(arr + mid, n - mid);
		long *left = new long[mid];
		long *right = new long[n - mid];
		for (int i = 0; i < mid; i++)
		{
			left[i] = arr[i];
		}
		for (int j = 0; j < n - mid; j++)
		{
			right[j] = 2 * arr[mid + j];
		}
		// _sort(left, mid);
		_sort(right, n - mid);
		//
		for (int i = 0; i < mid; i++)
		{
			long x = left[i];
			int index = _find(right, n - mid, x) + 1;
			count += index;
		}
		delete[] left;
		delete[] right;
		return count;
	}

	static int _find(const long *arr, int n, long x)
	{
		if (n < 5)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] >= x)
				{
					return (i - 1);
				}
			}
			return n - 1;
		}
		//
		int mid = n / 2;
		if (arr[mid] < x)
		{
			return mid + _find(arr + mid, n - mid, x);
		}
		else
		{
			return _find(arr, mid, x);
		}
	}

	static void _sort(long *arr, int n)
	{
		qsort((void*)arr, n, sizeof(long), _cmp);
	}

	static int _cmp(const void *a, const void *b)
	{
		long *pa = (long*)a;
		long *pb = (long*)b;
		if (*pa < *pb)
		{
			return -1;
		}
		if (*pa == *pb)
		{
			return 0;
		}
		if (*pa > *pb)
		{
			return 1;
		}
	}
};