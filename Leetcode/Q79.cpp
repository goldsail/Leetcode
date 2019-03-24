class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<pair<int, int>> path;
                    path.push_back(pair<int, int>(i, j));
                    //
                    if (exist(board, word, path)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    static bool exist(const vector<vector<char>> &board, const string &word, vector<pair<int, int>> &path) {
        
        if (path.size() == word.size()) {
            return true;
        }
        
        vector<pair<int, int>> incs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (pair<int, int> inc : incs) {
            int u = path.back().first + inc.first;
            int v = path.back().second + inc.second;
            
            if (u >= 0 && u < board.size() && v >= 0 && v < board[0].size()) {
                bool flag = false;
                for (pair<int, int> p : path) {
                    if (p.first == u && p.second == v) {
                        flag = true;
                        break;
                    }
                }
                
                if (!flag && board[u][v] == word[path.size()]) {
                    path.push_back(pair<int, int>(u, v));
                    bool result = exist(board, word, path);
                    path.pop_back();
                    if (result) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};