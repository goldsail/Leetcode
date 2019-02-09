class Solution {
public:
    int numDistinct(string s, string t) {
        
        if (s.size() < t.size()) {
            return 0;
        }
        
        vector<vector<int>> table = vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1));
        
        table[0][0] = 1;
        for (int i = 0; i < s.size(); i++) {
            table[i + 1][0] = 1;
        }
        for (int j = 0; j < t.size(); j++) {
            table[0][j + 1] = 0;
        }
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    table[i + 1][j + 1] = table[i][j + 1] + table[i][j];
                } else {
                    table[i + 1][j + 1] = table[i][j + 1];
                }
            }
        }
        
        return table[s.size()][t.size()];
    }
};