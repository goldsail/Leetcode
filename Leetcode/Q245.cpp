class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<string>::iterator it1 = words.end();
        vector<string>::iterator it2 = words.end();
        int result = numeric_limits<int>::max();
        if (word1 != word2) {
            for (auto it = words.begin(); it != words.end(); ++it) {
                if (it[0] == word1) {
                    it1 = it;
                    if (it2 != words.end()) {
                        result = min(result, int(it - it2));
                    }
                }
                if (it[0] == word2) {
                    it2 = it;
                    if (it1 != words.end()) {
                        result = min(result, int(it - it1));
                    }
                }
            }
        } else {
            for (auto it = words.begin(); it != words.end(); ++it) {
                if (it[0] == word1) {
                    if (it1 != words.end()) {
                        result = min(result, int(it - it1));
                    }
                    it1 = it;
                }
            }
        }
        
        return result;
    }
};
