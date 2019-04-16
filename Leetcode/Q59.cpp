class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        auto matrix = vector<vector<int>>(n, vector<int>(n));
        
        int u = 0;
        int k = n;
        
        int count = 0;
        
        while (k > 0) {
            if (k == 1) {
                matrix[u][u] = (++count);
                return matrix;
            } else {
                
                for (int i = u; i < u + k; i++) {
                    matrix[u][i] = (++count);
                }
                
                for (int i = u + 1; i < u + k; i++) {
                    matrix[i][u + k - 1] = (++count);
                }
                
                for (int i = u + k - 2; i >= u; i--) {
                    matrix[u + k - 1][i] = (++count);
                }
                
                for (int i = u + k - 2; i > u; i--) {
                    matrix[i][u] = (++count);
                }
                
                k -= 2;
                u += 1;
                
            }
            
        }
        
        return matrix;
    }
};