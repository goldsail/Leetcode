class Solution {
public:
    int minCut(string s) {
        
        if (s.size() == 0) {
            return 0;
        }
        
        vector<vector<bool>> table = getPalindromeTable(s);
        
        vector<int> results = vector<int>(s.size(), -1);
        
        return solve(s, 0, results, table) - 1;
    }
    
private:
    static vector<vector<bool>> getPalindromeTable(const string &s) {
        
        auto table = vector<vector<bool>>(s.size(), vector<bool>(s.size(), true));
        
        for (int p = 1; p < s.size(); p++) {
            for (int q = 0; p + q < s.size(); q++) {
                int i = q;
                int j = p + q;
                table[i][j] = (s[i] == s[j]) && table[i + 1][j - 1];
            }
        }
        
        return table;
        
        //   b a n a n a
        // b T F F F F F
        // a   T F T F T
        // n     T F T F
        // a       T F T
        // n         T F
        // a           T
    }
    
    static int min(int a, int b) {
        return a < b ? a : b;
    }
    
    static int solve(const string &s, int i, vector<int> &results, const vector<vector<bool>> &table) {
        if (i == s.size()) {
            return 0;
        }
        
        if (results[i] >= 0) {
            return results[i];
        }
        
        results[i] = INT_MAX;
        for (int j = i + 1; j <= s.size(); j++) {
            if (table[i][j - 1]) {
                results[i] = min(results[i], solve(s, j, results, table) + 1);
            }
        }
        return results[i];
    }
};