class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        dp = {{{ 0 }}};
        return help(boxes, 0, boxes.size(), 1);
    }
    
private:
    array<array<array<int, 101>, 101>, 101> dp;
    
    // tutple (i, j, k) defines the state space of the DP, where
    // i: start of interval (inclusive).
    // j: end of interval (exclusive).
    // k: number of adjacent same-color boxes on the left of b[i], including b[i].
    int help(const vector<int>& b, int i, int j, int k) {
        if (i == j) return 0; // trivial case
        if (dp[i][j][k] == 0) {
            // first try: truncate right after b[i].
            // the new interval now starts at b[i+1].
            int res = k * k + help(b, i + 1, j, 1);
            for (int u = i + 1; u < j; u++) {
                if (b[u] == b[i]) {
                    // another try: make b[i] and b[u] adjacent, and see if it improves.
                    // the interval now splits into two at b[u].
                    res = max(res, 
                              help(b, i + 1, u, 1) + help(b, u, j, k + 1));
                }
            }
            dp[i][j][k] = res;
        }
        return dp[i][j][k];
    }
};