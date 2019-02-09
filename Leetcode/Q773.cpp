class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> closed_set;
        queue<pair<string, int>> open_set;
        
        open_set.push(pair<string, int>(encode(board), 0));
        
        while (!open_set.empty()) {
            string current = open_set.front().first;
            int depth = open_set.front().second;
            open_set.pop();
            closed_set.insert(current);
            
            if (current == string("123450")) {
                return depth;
            }
            
            for (string neighbor : get_neighbors(current)) {
                if (closed_set.find(neighbor) == closed_set.end()) {
                    open_set.push(pair<string, int>(neighbor, depth + 1));
                }
            }
            
        }
        
        return -1;
        
    }
    
private:
    static string encode(const vector<vector<int>> &board) {
        char s[7];
        s[0] = '0' + board[0][0];
        s[1] = '0' + board[0][1];
        s[2] = '0' + board[0][2];
        s[3] = '0' + board[1][0];
        s[4] = '0' + board[1][1];
        s[5] = '0' + board[1][2];
        s[6] = '\0';
        return string(s);
    }
    
    static vector<string> get_neighbors(const string &str) {
        vector<string> ret;
        
        int p, q;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (str[i * 3 + j] == '0') {
                    p = i;
                    q = j;
                }
            }
        }
        
        for (pair<int, int> step : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int x = p + step.first;
            int y = q + step.second;
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                int i = p * 3 + q;
                int j = x * 3 + y;
                string s = str;
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                ret.push_back(s);
            }
        }
        
        return ret;
    }
};