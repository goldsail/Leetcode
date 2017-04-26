#include <string>

using namespace std;


class Solution 
{
public:
	string intToRoman(int num) 
	{
		return _parse(num);
	}

private:
	string _parse(int num)
	{
		string ret;
		if (num / 1000 > 0)
		{
			switch (num / 1000)
			{
			case 1:
				ret += "M";
				break;
			case 2:
				ret += "MM";
				break;
			case 3:
				ret += "MMM";
				break;
			}
			ret += _parse(num % 1000);
			return ret;
		}
		else if (num / 100 > 0)
		{
			switch (num / 100)
			{
			case 1:
				ret += "C";
				break;
			case 2:
				ret += "CC";
				break;
			case 3:
				ret += "CCC";
				break;
			case 4:
				ret += "CD";
				break;
			case 5:
				ret += "D";
				break;
			case 6:
				ret += "DC";
				break;
			case 7:
				ret += "DCC";
				break;
			case 8:
				ret += "DCCC";
				break;
			case 9:
				ret += "CM";
				break;
			}
			ret += _parse(num % 100);
			return ret;
		}
		else if (num / 10 > 0)
		{
			switch (num / 10)
			{
			case 1:
				ret += "X";
				break;
			case 2:
				ret += "XX";
				break;
			case 3:
				ret += "XXX";
				break;
			case 4:
				ret += "XL";
				break;
			case 5:
				ret += "L";
				break;
			case 6:
				ret += "LX";
				break;
			case 7:
				ret += "LXX";
				break;
			case 8:
				ret += "LXXX";
				break;
			case 9:
				ret += "XC";
				break;
			}
			ret += _parse(num % 10);
			return ret;
		}
		else
		{
			switch (num)
			{
			case 0:
				break;
			case 1:
				ret += "I";
				break;
			case 2:
				ret += "II";
				break;
			case 3:
				ret += "III";
				break;
			case 4:
				ret += "IV";
				break;
			case 5:
				ret += "V";
				break;
			case 6:
				ret += "VI";
				break;
			case 7:
				ret += "VII";
				break;
			case 8:
				ret += "VIII";
				break;
			case 9:
				ret += "IX";
				break;
			}
			return ret;
		}
	}
};