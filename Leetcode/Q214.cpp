class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        for (int L = s.size(); L >= 0; L--) {
            int i1 = (L - 1) / 2;
            int i2 = L / 2;
            while (i1 >= 0 && s[i1] == s[i2]) {
                i1--;
                i2++;
            }
            if (i1 < 0) {
                string t = s.substr(i2, s.size() - i2);
                reverse(t.begin(), t.end());
                return t + s;
            }
        }
        return s;
    }
};
