class Solution 
{
public:
	int countDigitOne(int n) 
	{
		const int M = 12;
		long pow[M];
		pow[0] = 1;
		for (int i = 1; i < M; i++)
		{
			pow[i] = 10 * pow[i - 1];
		}
		if (n < 0)
		{
			return 0;
		}
		int ret = 0;
		//
		for (int i = 1; i < M; i++)
		{
			ret += (n / pow[i]) * pow[i - 1];
			//
			switch ((n / pow[i - 1]) % 10)
			{
			case 0:
				break;
			case 1:
				ret += (n%pow[i - 1]) + 1;
				break;
			default:
				ret += pow[i - 1];
			}

		}
		return ret;
	}
};