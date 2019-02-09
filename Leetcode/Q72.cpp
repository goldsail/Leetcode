class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> table = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1));
        
        table[0][0] = 0;
        for (int i = 0; i < word1.size(); i++) {
            table[i + 1][0] = i + 1;
        }
        for (int j = 0; j < word2.size(); j++) {
            table[0][j + 1] = j + 1;
        }
        
        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                    
                int score_replace = table[i][j] + (word1[i] != word2[j]);
                int score_insert = table[i][j + 1] + 1;
                int score_delete = table[i + 1][j] + 1;
                
                table[i + 1][j + 1] = min(score_replace, min(score_insert, score_delete));
            }
        }
        
        if (false) {
            for (int i = 0; i <= word1.size(); i++) {
                for (int j = 0; j <= word2.size(); j++) {
                    cout << table[i][j] << ' ';
                }
                cout << endl;
            }
        }
        
        return table[word1.size()][word2.size()];
    }
    
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
};