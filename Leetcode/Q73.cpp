class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = getDifferentNumber(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    
                    for (int u = 0; u < matrix.size(); u++) {
                        if (matrix[u][j] != 0) {
                            matrix[u][j] = M;
                        }
                    }
                    
                    for (int v = 0; v < matrix[0].size(); v++) {
                        if (matrix[i][v] != 0) {
                            matrix[i][v] = M;
                        }
                    }
                    
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == M) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    int getDifferentNumber(const vector<vector<int>> &matrix) {
        for (int x = INT_MIN; x <= INT_MAX; x++) {
            bool flag = true;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == x) {
                        flag = false;
                    }
                }
            }
            if (flag) return x;
        }
        return 0;
    }
};