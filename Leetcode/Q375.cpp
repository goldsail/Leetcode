class Solution {
public:
    int getMoneyAmount(int n) {
        auto dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return help(1, n, dp);
    }
    
private:
    int help(int lo, int hi, vector<vector<int>> &dp) {
        if (lo >= hi) return 0;
        if (dp[lo][hi] < 0) {
            int res = INT_MAX;
            for (int x = lo; x <= hi; x++) {
                res = min(res, x + max(
                    help(lo, x - 1, dp),
                    help(x + 1, hi, dp)
                ));
            }
            dp[lo][hi] = res;
        }
        return dp[lo][hi];
    }
};