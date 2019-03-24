class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        this->mem = vector<char>(s.size(), 'U');
        this->results = unordered_set<string>();
        this->stk = vector<string>();
        wordBreak(s, 0);
        return vector<string>(results.begin(), results.end());
    }
    
private:
    unordered_set<string> wordSet;
    vector<char> mem;
    unordered_set<string> results;
    vector<string> stk; // a stack of words
    
    void wordBreak(const string &s, size_t pos) {
        if (pos == s.size()) {
            string str;
            for (const string &s : stk) {
                str += s;
                str += " ";
            }
            str.pop_back();
            results.insert(str);
            return;
        }
        
        if (mem[pos] == 'F') {
            return;
        }
        
        for (int i = pos + 1; i <= s.size(); i++) {
            if (wordSet.find(s.substr(pos, i - pos)) != wordSet.end()) {
                stk.push_back(s.substr(pos, i - pos));
                wordBreak(s, i);
                stk.pop_back();
                if (i == s.size() || mem[i] == 'T') {
                    mem[pos] = 'T';
                }
                
            }
        }
        
        if (mem[pos] == 'U') {
            mem[pos] = 'F';
        }
        
        return;
    }
};