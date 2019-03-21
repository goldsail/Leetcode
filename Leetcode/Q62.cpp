class Solution {
public:
    int uniquePaths(int m, int n) {
        mem = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return uniquePaths_(m, n);
    }
    
private:
    vector<vector<int>> mem;
    
    int uniquePaths_(int m, int n) {
        if (mem[m][n] >= 0) {
            return mem[m][n];
        }
        //
        int ans;
        if (m == 1) {
            if (n == 1) {
                ans = 1;
            } else {
                ans = uniquePaths_(1, n - 1);
            }
        } else {
            if (n == 1) {
                ans = uniquePaths_(m - 1, 1);
            } else {
                ans = uniquePaths_(m - 1, n) + uniquePaths_(m, n - 1);
            }
        }
        mem[m][n] = ans;
        return ans;
    }
};