class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        auto dp = vector<int>(s.size(), -1);
        return help(s, 0, dp);
    }
    
private:
    int help(const string& s, int i, vector<int>& dp) {
        if (i >= s.size()) return 1;
        if (i == s.size() - 1) return (s[i] > '0');
        if (dp[i] < 0) {
            if (s[i] - '0' == 0) return 0;
            int x = 10 * (s[i] - '0') + (s[i + 1] - '0');
            if (x > 26) {
                dp[i] = help(s, i + 1, dp);
            } else {
                dp[i] = help(s, i + 1, dp) + help(s, i + 2, dp);
            }
        }
        return dp[i];
    }
};
