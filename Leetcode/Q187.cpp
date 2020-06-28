class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> result;
        const int L = 10;
        for (int i = 0; i + L <= s.size(); i++) {
            string sub = s.substr(i, L);
            ++seen[sub];
        }
        for (auto it = seen.begin(); it != seen.end(); ++it) {
            if (it->second > 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};
