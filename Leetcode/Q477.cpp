#include <vector>

using namespace std;



class Solution 
{
	int arr[31] = { 0x40000000, 0x20000000, 0x10000000, 
		0x8000000, 0x4000000, 0x2000000, 0x1000000, 
		0x800000, 0x400000, 0x200000, 0x100000, 
		0x80000, 0x40000, 0x20000, 0x10000, 
		0x8000, 0x4000, 0x2000, 0x1000, 
		0x800, 0x400, 0x200, 0x100, 
		0x80, 0x40, 0x20, 0x10, 
		0x8, 0x4, 0x2, 0x1 };

public:
	int totalHammingDistance(vector<int>& nums) 
	{
		int n = nums.size();
		int *v = new int[n];
		for (int i = 0; i < n; i++)
			v[i] = nums[i];
		//
		int result[31];
		for (int i = 0; i < 31; i++)
			result[i] = 0;
		//
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 31; j++)
			{
				if (v[i] & arr[j])
					result[j]++;
			}
		}
		//
		int ret = 0;
		for (int i = 0; i < 31; i++)
		{
			ret += (result[i]) * (n - result[i]);
		}
		return ret;
	}
};