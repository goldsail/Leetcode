class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i = 1; i < costs.size(); i++) {
            int firstMin = numeric_limits<int>::max();
            int secondMin = numeric_limits<int>::max();
            for (int j = 0; j < costs[0].size(); j++) {
                if (dp[i - 1][j] < firstMin) {
                    secondMin = firstMin;
                    firstMin = dp[i - 1][j];
                } else if (dp[i - 1][j] < secondMin) {
                    secondMin = dp[i - 1][j];
                }
            }
            for (int j = 0; j < costs[0].size(); j++) {
                if (dp[i - 1][j] == firstMin) {
                    dp[i][j] = costs[i][j] + secondMin;
                } else {
                    dp[i][j] = costs[i][j] + firstMin;
                }
            }
        }
        int result = numeric_limits<int>::max();
        for (int j = 0; j < costs[0].size(); j++) {
            result = min(result, dp[costs.size() - 1][j]);
        }
        return result;
    }
};
