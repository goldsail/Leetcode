class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        return minPathSum(grid, 0, 0, mem);
    }
    
private:
    static int minPathSum(const vector<vector<int>> &grid, int i, int j, vector<vector<int>> &mem) {
        if (mem[i][j] >= 0) return mem[i][j];
        
        // cout << i << ' ' << j << endl;
        
        int ans;
        if (i == int(grid.size()) - 1) {
            if (j == int(grid[0].size()) - 1) {
                ans = grid[i][j];
            } else {
                ans = grid[i][j] + minPathSum(grid, i, j + 1, mem);
            }
        } else {
            if (j == int(grid[0].size()) - 1) {
                ans = grid[i][j] + minPathSum(grid, i + 1, j, mem);
            } else {
                ans = grid[i][j] + min(
                    minPathSum(grid, i, j + 1, mem),
                    minPathSum(grid, i + 1, j, mem)
                );
            }
        }
        
        mem[i][j] = ans;
        return ans;
    }
};
