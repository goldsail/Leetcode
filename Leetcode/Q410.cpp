class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto dp = vector<vector<long>>(nums.size(), vector<long>(m));
        
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            dp[i][0] = sum;
        }
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= i && j < m; j++) {
                long sum = 0;
                long result = numeric_limits<int>::max();
                for (int k = i; k > 0; k--) {
                    sum += nums[k];
                    result = min(result, max(sum, dp[k - 1][j - 1]));
                }
                dp[i][j] = result;
            }
        }
        return dp[nums.size() - 1][m - 1];
    }
};
