class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        const int K = 2;
        
        // Greedy approach for Set Intersecion Size At Least K
        // Time complexity O(K * N^2)
        
        sort(intervals.begin(), intervals.end(), less);
        
        unordered_set<int> result;
        vector<int> todo = vector<int>(intervals.size(), K);
        
        for (int i = intervals.size() - 1; i >= 0; i--) {
            if (intervals[i][1] - intervals[i][0] + 1 < K) return -1; // interval length less than K: impossible
            for (int x = intervals[i][0]; x <= intervals[i][1]; x++) {
                if (todo[i] == 0) break;
                if (result.find(x) == result.end()) {
                    result.insert(x);
                    for (int j = 0; j < i; j++) {
                        if (todo[j] > 0 && intervals[j][0] <= x && x <= intervals[j][1]) {
                            todo[j]--;
                        }
                    }
                    todo[i]--;
                }
            }
        }
        
        return result.size();
    }
    
private:
    static bool less(const vector<int> &a, const vector<int> &b) {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    }
};