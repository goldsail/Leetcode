class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<vector<bool>> table = vector<vector<bool>>(s1.size() + 1, vector<bool>(s2.size() + 1));
        
        table[0][0] = true;
        for (int i = 0; i < s1.size(); i++) {
            table[i + 1][0] = table[i][0] && (s1[i] == s3[i]);
        }
        for (int j = 0; j < s2.size(); j++) {
            table[0][j + 1] = table[0][j] && (s2[j] == s3[j]);
        }
        
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                
                bool temp1 = table[i][j + 1] && (s1[i] == s3[i + j + 1]);
                
                bool temp2 = table[i + 1][j] && (s2[j] == s3[i + j + 1]);
                
                table[i + 1][j + 1] = temp1 || temp2;
                
            }
        }
        
        return table[s1.size()][s2.size()];
        
    }
};