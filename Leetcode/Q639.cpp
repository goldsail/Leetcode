class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        auto dp = vector<vector<int>>(10, vector<int>(s.size(), -1));
        int result = 0;
        for (int curr = 0; curr <= 9; curr++) {
            add(result, help(s, 0, curr, dp));
        }
        return result;
    }
    
private:
    void add(int& a, int b) {
        const int M = 1e9 + 7;
        a = (a % M + b % M) % M;
    }
    
    int help(const string& s, int i, int curr, vector<vector<int>>& dp) {
        if (i >= s.size()) return 1;
        if (curr == 0) return 0;
        if (s[i] != '*' && s[i] != '0' + curr) return 0;
        if (i == s.size() - 1) return 1;
        //
        if (dp[curr][i] < 0) {
            dp[curr][i] = 0;
            for (int next = 0; next <= 9; next++) {
                add(dp[curr][i], help(s, i + 1, next, dp));
                int num = 10 * curr + next;
                if (num <= 26) {
                    if ((next != 0 && s[i + 1] == '*') || s[i + 1] == '0' + next) {
                        if (i + 2 >= s.size()) {
                            add(dp[curr][i], 1);
                        } else {
                            for (int next2 = 0; next2 <= 9; next2++) {
                                add(dp[curr][i], help(s, i + 2, next2, dp));
                            }
                        }
                    }
                }
            }
        }
        return dp[curr][i];
    }
};
