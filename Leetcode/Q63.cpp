class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> &g = obstacleGrid;
        mem = vector<vector<int>>(g.size(), vector<int>(g[0].size(), -1));
        return uniquePaths_(0, 0, g);
    }
    
private:
    vector<vector<int>> mem;
    
    int uniquePaths_(int m, int n, const vector<vector<int>>& g) {
        if (mem[m][n] >= 0) {
            return mem[m][n];
        }
        //
        int ans;
        if (g[m][n] == 1) {
            ans = 0;
        } else if (m == int(g.size()) - 1) {
            if (n == int(g[0].size()) - 1) {
                ans = 1;
            } else {
                ans = uniquePaths_(m, n + 1, g);
            }
        } else {
            if (n == int(g[0].size()) - 1) {
                ans = uniquePaths_(m + 1, n, g);
            } else {
                ans = uniquePaths_(m + 1, n, g) + uniquePaths_(m, n + 1, g);
            }
        }
        mem[m][n] = ans;
        return ans;
    }
};