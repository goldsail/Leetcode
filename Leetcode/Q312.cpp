class Solution {
public:
    int maxCoins(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        return help(nums, 0, nums.size() + 1);
    }
    
private:
    vector<vector<int>> dp;
    
    int help(const vector<int>& nums, int i, int j) {
        assert(0 <= i && i <= j && j <= nums.size() + 1);
        if (dp[i][j] < 0) {
            int result = 0;
            for (int k = i + 1; k < j; k++) {
                int left = (i == 0) ? 1 : nums[i - 1];
                int right = (j == nums.size() + 1) ? 1 : nums[j - 1];
                int temp = help(nums, i, k) + 
                           help(nums, k, j) + 
                           left * nums[k - 1] * right;
                result = max(result, temp);
            }
            dp[i][j] = result;
        }
        return dp[i][j];
    }
};
