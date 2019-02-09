class Solution {
public:
    bool isScramble(string s1, string s2) {
        return s1.size() == s2.size() && isScramble_(s1.data(), s2.data(), s1.size());
    }
    
private:
    bool isScramble_(const char *s1, const char *s2, int length) {
        if (length == 0) {
            return true;
        }
        if (length == 1) {
            return s1[0] == s2[0];
        }
        
        // Split s1 into two strings: [0, i) and [i, length).
        // left1 is the char hashmap for s1[0, i)
        // right1 is the char hashmap for s1[i, length)
        // 
        // There are two ways to split s2:
        // 
        // (a, forward direction) Split s2 into [0, i) and [i, length)
        // left2a is the char hashmap for s2[0, i)
        // right2a is the char hashmap for s2[i, length)
        //
        // (b, backward direction) Split s2 into [0, length - i) and [length - i, length)
        // left2b is the char hashmap for s2[0, length - i)
        // right2b is the char hashmap for s2[length - i, length)
        // 
        // Initialize the char hashmaps
        unordered_map<char, int> left1, left2a, left2b, right1, right2a, right2b;
        for (int i = 0; i < length; i++) {
            right1[s1[i]]++;
            right2a[s2[i]]++;
            left2b[s2[i]]++;
        }
        
        // For each cutoff position in range (0, length):
        // Recursively, return true if
        // s1 left matches with s2 left a and s1 right matches with s2 right a, or
        // s1 left matches with s2 right b and s1 right matches with s2 left b.
        for (int i = 1; i < length; i++) {
            left1[s1[i - 1]]++;
            left2a[s2[i - 1]]++;
            right2b[s2[length - i]]++;
            right1[s1[i - 1]]--;
            right2a[s2[i - 1]]--;
            left2b[s2[length - i]]--;
            if (left1 == left2a && right1 == right2a) {
                if (isScramble_(s1, s2, i) && isScramble_(s1 + i, s2 + i, length - i)) {
                    return true;
                }
            }
            if (left1 == right2b && right1 == left2b) {
                if (isScramble_(s1, s2 + length - i, i) && isScramble_(s1 + i, s2, length - i)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};