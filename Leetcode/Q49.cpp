class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> wordMap;
        for (string s : strs) {
            array<int, 26> arr = getWordCount(s);
            if (wordMap.find(arr) == wordMap.end()) {
                wordMap[arr] = vector<string>();
            }
            wordMap[arr].push_back(s);
        }
        
        vector<vector<string>> results;
        for (auto it = wordMap.begin(); it != wordMap.end(); ++it) {
            results.push_back(it->second);
        }
        return results;
    }
    
private:
    static array<int, 26> getWordCount(const string &word) {
        array<int, 26> arr = {0};
        for (char c : word) {
            ++(arr.at(c - 'a'));
        }
        return arr;
    }
};