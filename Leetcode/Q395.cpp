class Solution {
public:
    int longestSubstring(string s, int k) {
        return help(s.begin(), s.end(), k);
    }
    
private:
    int help(string::iterator start, string::iterator end, int k) {
        if (end - start < k) return 0;
        //
        unordered_map<char, int> count;
        for (auto it = start; it != end; ++it) {
            ++count[*it];
        }
        auto begin = start;
        int result = 0;
        for (auto it = start; it != end; ++it) {
            if (count[*it] < k) {
                if (count[*begin] >= k) {
                    result = max(result, help(begin, it, k));
                }
                begin = it;
            } else {
                if (count[*begin] < k) {
                    begin = it;
                }
            }
        }
        if (begin == start) return end - start;
        if (count[*begin] >= k) {
            result = max(result, help(begin, end, k));
        }
        return result;
    }
};
