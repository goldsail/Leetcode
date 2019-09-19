class Solution {
public:
    int numSquares(int n) {
        assert(n > 0);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int temp = numeric_limits<int>::max();
            for (int j = 1; j * j <= i; j++) {
                temp = min(temp, 1 + dp[i - j * j]);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
