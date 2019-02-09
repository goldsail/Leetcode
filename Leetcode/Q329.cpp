class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        
        this->results = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < results[0].size(); j++) {
                visit(matrix, pair<int, int>(i, j));
            }
        }
        
        int ret = 0;
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < results[0].size(); j++) {
                ret = max(ret, results[i][j]);
            }
        }
        return ret;
    }
    
private:
    vector<vector<int>> results;
    vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void visit(const vector<vector<int>> &matrix, pair<int, int> position) {
        int i = position.first;
        int j = position.second;
        
        if (results[i][j] >= 0) {
            return;
        }
        
        int ret = 0;
        for (pair<int, int> neighbor : neighbors) {
            int u = i + neighbor.first;
            int v = j + neighbor.second;
            if (u >= 0 && u < matrix.size() && v >= 0 && v < matrix[0].size()) {
                if (matrix[u][v] > matrix[i][j]) {
                    visit(matrix, pair<int, int>(u, v));
                    ret = max(ret, results[u][v]);
                }
            }
        }
        results[i][j] = ret + 1;
        
    }
    
    static int max(int a, int b) {
        return a > b ? a : b;
    }
};