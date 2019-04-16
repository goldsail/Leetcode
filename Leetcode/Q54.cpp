class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        
        int M = matrix.size();
        if (M == 0) return result;
        int N = matrix[0].size();
        if (N == 0) return result;
        
        int u = 0;
        int v = 0;
        
        while (M > 0 && N > 0) {
            if (M == 1) {
                for (int i = v; i < v + N; i++) {
                    result.push_back(matrix[u][i]);
                }
                return result;
            } else if (N == 1) {
                for (int i = u; i < u + M; i++) {
                    result.push_back(matrix[i][v]);
                }
                return result;
            } else {
                
                for (int i = v; i < v + N; i++) {
                    result.push_back(matrix[u][i]);
                }
                
                for (int i = u + 1; i < u + M; i++) {
                    result.push_back(matrix[i][v + N - 1]);
                }
                
                for (int i = v + N - 2; i >= v; i--) {
                    result.push_back(matrix[u + M - 1][i]);
                }
                
                for (int i = u + M - 2; i > u; i--) {
                    result.push_back(matrix[i][v]);
                }
                
                M -= 2;
                N -= 2;
                u += 1;
                v += 1;
                
            }
            
        }
        
        return result;
    }
};