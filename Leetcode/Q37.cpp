class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
    
private:
    typedef vector<vector<char>> Board;
    
    bool solve(Board &b, int pos) {
        if (pos == 81) {
            return true;
        }
        
        int i = pos / 9;
        int j = pos % 9;
        
        if (b[i][j] == '.') {
            
            // try position b[i][j]
            
            // these are candidate numbers for b[i][j]
            // first assume they are all valid
            bool candidates[9];
            for (int k = 0; k < 9; k++) {
                candidates[k] = true;
            }
            
            // rule out those already in the row
            for (int q = 0; q < 9; q++) {
                if (b[i][q] != '.') {
                    candidates[b[i][q] - '1'] = false;
                }
            }
            
            // rule out those already in the column
            for (int p = 0; p < 9; p++) {
                if (b[p][j] != '.') {
                    candidates[b[p][j] - '1'] = false;
                }
            }
            
            // rule out those already in the cell
            for (int p = i - (i % 3); p < i - (i % 3) + 3; p++) {
                for (int q = j - (j % 3); q < j - (j % 3) + 3; q++) {
                    if (b[p][q] != '.') {
                        candidates[b[p][q] - '1'] = false;
                    }
                }
            }
            
            // try each valid candidate recursively
            for (int k = 0; k < 9; k++) {
                if (candidates[k]) {
                    b[i][j] = k + '1';
                    if (solve(b, pos + 1)) {
                        // return true immediately if one candidate is a solution
                        return true;
                    } else {
                        // traceback and try next candidate
                        b[i][j] = '.';
                    }
                }
            }
            // if no candidates lead to a solution, return false
            return false;
            
        } else {
            
            // skip position b[i][j] which is already filled in
            return solve(b, pos + 1);
            
        }
    }
};