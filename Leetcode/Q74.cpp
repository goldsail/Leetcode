class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        return searchMatrix(matrix, target, 0, matrix.size() * matrix[0].size());
    }
    
private:
    static int get(const vector<vector<int>> &matrix, int idx) {
        return matrix[idx / matrix[0].size()][idx % matrix[0].size()];
    }
    
    static bool searchMatrix(const vector<vector<int>> &matrix, int target, int lo, int hi) {
        if (hi - lo < 5) {
            for (int i = lo; i < hi; i++) {
                if (get(matrix, i) == target) {
                    return true;
                }
            }
            return false;
        }
        
        int mid = (lo + hi) / 2;
        int x = get(matrix, mid);
        if (x < target) {
            return searchMatrix(matrix, target, mid + 1, hi);
        } else if (x > target) {
            return searchMatrix(matrix, target, lo, mid);
        } else {
            return true;
        }
    }
};