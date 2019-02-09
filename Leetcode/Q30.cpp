class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;
        
        int number = words.size();
        if (number == 0) {
            return result;
        }
        
        int length = words[0].size();
        if (length == 0 || s.size() < length * number) {
            return result;
        }
        
        // construct a hashmap for words
        unordered_map<string, int> word_map;
        for (string word : words) {
            word_map[word]++;
        }
        
        // for each position i
        for (int i = 0; i <= s.size() - length * number; i++) {
            
            // construct a hashmap for substring words
            unordered_map<string, int> temp_map;
            for (int j = 0; j < number; j++) {
                string word = s.substr(i + j * length, length);
                temp_map[word]++;
            }
            
            // position i is valid if two hashmaps equal
            if (temp_map == word_map) {
                result.push_back(i);
            }
            
        }
        
        return result;
    }
};