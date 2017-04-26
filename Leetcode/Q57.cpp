#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		int y1 = newInterval.start;
		int y2 = newInterval.end;
		for (auto iter = intervals.begin(); iter != intervals.end(); iter++)
		{
			int x1 = iter->start;
			int x2 = iter->end;
			if (x2 >= y1 && x1 <= y2)
			{
				y1 = (x1 < y1) ? x1 : y1;
				y2 = (x2 > y2) ? x2 : y2;
			}
			else
			{
				ret.push_back(*iter);
			}
		}
		auto temp = Interval(y1, y2);
		int index = ret.size();
		for (int i = 0; i < index; i++)
		{
			if (ret[i].start > y1)
			{
				index = i;
			}
		}
		if (index < ret.size())
		{
			ret.insert(ret.begin() + index, temp);
		}
		else
		{
			ret.push_back(temp);
		}
		return ret;
	}
};