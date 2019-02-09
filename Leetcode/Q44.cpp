class Solution {
public:
    bool isMatch(string s, string p) {
        
        bool result = false;
        
        // create the 2D table for dynamic programming
        bool **table = new bool*[p.size() + 1];
        for (int i = 0; i < p.size() + 1; i++) {
            table[i] = new bool[s.size() + 1];
        }
        
        // initialize the table's first row and first column
        table[0][0] = true;
        for (int j = 0; j < s.size(); j++) {
            table[0][j + 1] = false;
        }
        for (int i = 0; i < p.size(); i++) {
            table[i + 1][0] = table[i][0] && (p[i] == '*');
        }
        
        // calculate other entries using DP
        for (int i = 0; i < p.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                switch (p[i]) {
                    case '*':
                        table[i + 1][j + 1] = table[i + 1][j] || table[i][j] || table[i][j + 1];
                        break;
                    case '?':
                        table[i + 1][j + 1] = table[i][j];
                        break;
                    default:
                        table[i + 1][j + 1] = table[i][j] && (p[i] == s[j]);
                        break;
                }
            }
        }
        
        result = table[p.size()][s.size()];
        
        // destroy the 2D table
        for (int i = 0; i < p.size() + 1; i++) {
            delete[] table[i];
        }
        delete[] table;
        return result;
    }
};
