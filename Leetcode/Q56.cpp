/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        
        vector<Interval> results;
        for (Interval interval : intervals) {
            if (results.empty() || results.back().end < interval.start) {
                results.push_back(interval);
            } else if (results.back().end < interval.end) {
                results.back().end = interval.end;
            }
        }
        return results;
    }
};