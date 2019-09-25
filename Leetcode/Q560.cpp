class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        vector<int> sums = vector<int>(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
        //
        unordered_map<int, vector<vector<int>::iterator>> map;
        for (auto it = sums.begin(); it != sums.end(); ++it) {
            map[*it].push_back(it);
        }
        //
        int result = 0;
        for (auto it = sums.begin(); it != sums.end(); ++it) {
            for (auto jt : map[k + *it]) {
                if (it < jt) {
                    result++;
                }
            }
        }
        return result;
    }
};
