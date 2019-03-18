class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        if (s.size() == 0) {
            return vector<vector<string>>();
        }
        
        this->s = s;
        this->table = getPalindromeTable(s);
        this->results = vector<vector<string>>();
        this->stk = vector<string>();
        
        solve(0);
        
        return results;
    }
    
private:
    
    string s;
    vector<vector<bool>> table;
    vector<vector<string>> results;
    vector<string> stk; // a stack
    
    static vector<vector<bool>> getPalindromeTable(string s) {
        
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
    
    void solve(int i) {
        if (i == s.size()) {
            results.push_back(stk);
            return;
        }
        
        for (int j = i + 1; j <= s.size(); j++) {
            if (table[i][j - 1]) {
                stk.push_back(s.substr(i, j - i));
                solve(j);
                stk.pop_back();
            }
        }
        return;
    }
};