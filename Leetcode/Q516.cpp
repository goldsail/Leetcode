class Solution {
public:
    int longestPalindromeSubseq(string s) {
        dp = vector(s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size() - 1, s);
    }
    
private:
    vector<vector<int>> dp;
    int solve(int i, int j, const string& s) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] < 0) {
            if (s[i] == s[j]) {
                dp[i][j] = solve(i + 1, j - 1, s) + 2;
            } else {
                dp[i][j] = max(solve(i + 1, j, s), solve(i, j - 1, s));
            }
        }
        return dp[i][j];
        
    }
};
