#include <stdlib.h>

class Solution 
{
public:
	int divide(int dividend, int divisor) 
	{
		if (divisor == 0)
			return INT_MAX;
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		if (dividend == 0)
			return 0;
		bool isNegative = (dividend > 0) ^ (divisor > 0); 
		//
		int a = (dividend > 0) ? dividend : -dividend;
		int b = (divisor > 0) ? divisor : -divisor;
		//
		return isNegative ? -_divide(a, b) : _divide(a, b);
	}

private:
	int _divide(int _a, int _b)
	{
		if (_b == 1)
			return _a;
		if (_a < _b)
			return 0;
		int curr = _b;
		int count = 0;
		int temp = 1;
		while (curr < _a && curr > 0)
		{
			curr += curr;
			
			temp += temp;
			count++;
		}
		return ((temp >> 1) + _divide(_a - (curr >> 1), _b));
	}
};