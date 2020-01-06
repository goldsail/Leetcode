class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals = map<int, int>();
    }
    
    void addNum(int val) {
        auto right = intervals.upper_bound(val);
        auto left = right;
        if (right == intervals.begin()) {
            left = intervals.end();
        } else {
            --left;
        }
        if (left == intervals.end()) {
            if (right == intervals.end()) {
                intervals[val] = val;
            } else {
                if (val == right->first - 1) {
                    int temp = right->second;
                    intervals.erase(right);
                    intervals[val] = temp;
                } else {
                    intervals[val] = val;
                }
            }
        } else {
            if (right == intervals.end()) {
                if (val == left->second + 1) {
                    left->second = val;
                } else if (val > left->second + 1) {
                    intervals[val] = val;
                }
            } else {
                if (val == left->second + 1) {
                    if (val == right->first - 1) {
                        int temp = right->second;
                        left->second = temp;
                        intervals.erase(right);
                    } else {
                        left->second = val;
                    }
                } else {
                    if (val == right->first - 1) {
                        int temp = right->second;
                        intervals.erase(right);
                        intervals[val] = temp;
                    } else if (val > left->second + 1) {
                        intervals[val] = val;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            result.push_back(vector<int>{ it->first, it->second });
        }
        return result;
    }
    
private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
