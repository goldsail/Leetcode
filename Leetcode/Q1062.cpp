class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int lo = 0;
        int hi = S.size() - 1;
        if (hi < lo) return 0;
        do {
            if (hi - lo < 5) {
                for (int i = hi; i >= lo; i--) {
                    if (binarySearch(S, i)) return i;
                }
                return -1;
            }
            int mi = (lo + hi) / 2;
            if (binarySearch(S, mi)) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        } while (true);
        return -1;
    }
    
private:
    bool binarySearch(const string& s, int len) {
        if (len == 0) return true;
        unordered_set<string> record;
        for (int i = 0; i + len <= s.size(); i++) {
            string t = s.substr(i, len);
            if (record.find(t) != record.end()) {
                return true;
            }
            record.insert(t);
        }
        return false;
    }
};
