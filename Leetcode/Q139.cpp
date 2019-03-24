class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        this->mem = vector<char>(s.size(), 'U');
        return wordBreak(s, 0);
    }
    
private:
    unordered_set<string> wordSet;
    vector<char> mem;
    
    bool wordBreak(const string &s, size_t pos) {
        if (pos == s.size()) return true;
        
        if (mem[pos] != 'U') {
            return mem[pos] == 'T';
        }
        
        for (int i = pos + 1; i <= s.size(); i++) {
            if (wordSet.find(s.substr(pos, i - pos)) != wordSet.end()) {
                if (wordBreak(s, i)) {
                    mem[pos] = 'T';
                    return true;
                }
            }
        }
        
        mem[pos] = 'F';
        return false;
    }
};