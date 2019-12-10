class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        sums = vector<int>{ 0 };
        for (int x : stones) sums.push_back(sums.back() + x);
        dp = vector(stones.size(), vector(stones.size() + 1, 
                                         vector<int>(K + 1, -2)));
        return solve(0, stones.size(), 1, K);
    }
    
private:
    vector<vector<vector<int>>> dp;
    vector<int> sums;
    int solve(int i, int j, int k, int K) {
        if (dp[i][j][k] > -2) return dp[i][j][k];
        int result;
        if (j - i == 1) {
            result = (k == 1) ? 0 : (-1);
        } else if (k == 1) {
            int temp = solve(i, j, K, K);
            result = temp < 0 ? (-1) : temp + sums[j] - sums[i];
        } else { // j - i > 1 && k > 1
            result = numeric_limits<int>::max();
            for (int m = i + 1; m < j; m++) {
                int temp1 = solve(i, m, 1, K);
                int temp2 = solve(m, j, k - 1, K);
                if (temp1 >= 0 && temp2 >= 0) {
                    result = min(result, temp1 + temp2);
                }
            }
            if (result == numeric_limits<int>::max()) {
                result = -1;
            }
        }
        dp[i][j][k] = result;
        return result;
    }
};
