class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> posMap;
        vector<int> sums = vector<int>{ 0 };
        posMap[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currSum = sums.back() + nums[i];
            sums.push_back(currSum);
            if (posMap.find(currSum) == posMap.end()) {
                posMap[currSum] = i + 1;
            }
            int target = currSum - k;
            if (posMap.find(target) != posMap.end()) {
                result = max(result, i + 1 - posMap[target]);
            }
        }
        return result;
    }
};
