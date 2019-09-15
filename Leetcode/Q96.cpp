class Solution {
public:
    int numTrees(int n) {
        assert(n > 0);
        auto dp = vector<int>(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        //
        for (int k = 1; k < n; k++) {
            int count = 0;
            for (int i = 0; i <= k; i++) {
                count += dp[i] * dp[k - i];
            }
            dp[k + 1] = count;
        }
        return dp[n];
    }
};

