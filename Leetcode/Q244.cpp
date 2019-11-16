class WordDistance {
public:
    WordDistance(vector<string>& words) {
        wordMap = unordered_map<string, set<int>>();
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]].insert(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int result = numeric_limits<int>::max();
        assert(word1 != word2);
        const set<int>& set1 = wordMap.at(word1);
        const set<int>& set2 = wordMap.at(word2);
        for (int i : set1) {
            auto it = set2.upper_bound(i);
            if (it != set2.end()) {
                result = min(result, (*it) - i);
            }
        }
        for (int i : set2) {
            auto it = set1.upper_bound(i);
            if (it != set1.end()) {
                result = min(result, (*it) - i);
            }
        }
        return result;
    }
    
private:
    unordered_map<string, set<int>> wordMap;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
