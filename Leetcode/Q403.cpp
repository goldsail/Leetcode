class Solution {
public:
    bool canCross(vector<int>& stones) {
        // Dynamic Programming
        // dp[i][j]: current position at i-th stone when the last jump was j units
        // dp[i][j] == 'U': Unexplored
        // dp[i][j] == 'T': True
        // dp[i][j] == 'F': False
        
        if (stones.size() < 2) return false;
        if (stones[0] != 0) return false;
        if (stones[1] != 1) return false;
        
        this->stoneMap = unordered_map<int, int>();
        for (int i = 0; i < stones.size(); i++) {
            stoneMap[stones[i]] = i;
        }
        
        this->dp = vector<vector<char>>(stones.size(), vector<char>(stones.size(), 'U'));
        
        solve(stones, 1, 1);
        
        return (dp[1][1] == 'T');
    }
    
private:
    void solve(const vector<int> &stones, int i, int j) {
        if (dp[i][j] == 'U') {
            if (i == stones.size() - 1) {
                dp[i][j] = 'T';
                return;
            }
            int step;
            for (int step : vector<int>{ j - 1, j, j + 1 }) {
                if (step > 0) {
                    auto it = stoneMap.find(stones[i] + step);
                    if (it != stoneMap.end()) {
                        solve(stones, it->second, step);
                        if (dp[it->second][step] == 'T') {
                            dp[i][j] = 'T';
                            return;
                        }
                    }
                }
            }
            dp[i][j] = 'F';
        }
    }
    
    unordered_map<int, int> stoneMap;
    vector<vector<char>> dp;
};