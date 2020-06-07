class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int N = S.size();
        dp = vector(N, vector(N, vector<int>(4, -1)));
        int sum = 0;
        for (int k = 0; k < 4; k++) {
            dp[0][N-1][k] = solve(S, 0, N-1, k);
            sum = add(sum, dp[0][N-1][k]);
        }
        return sum;
    }
    
private:
    const int M = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int add(int a, int b) {
        return (a + b) % M;
    }
    
    int solve(const string &S, int i, int j, int k) {
        int N = S.size();
        char c = 'a' + k;
        if (j - i < 0) return 0;
        if (j - i == 0) {
            return (S[i] == c) ? 1 : 0;
        }
        // j - i > 0
        if (dp[i][j][k] >= 0) return dp[i][j][k];
        if (S[i] == c) {
            if (S[j] == c) {
                int sum = 2;
                for (int l = 0; l < 4; l++) {
                    sum = add(sum, solve(S, i+1, j-1, l));
                }
                dp[i][j][k] = sum;
            } else {
                dp[i][j][k] = solve(S, i, j-1, k);
            }
        } else {
            if (S[j] == c) {
                dp[i][j][k] = solve(S, i+1, j, k);
            } else {
                dp[i][j][k] = solve(S, i+1, j-1, k);
            }
        }
        return dp[i][j][k];
    }
};
