class Solution {
private: 
    enum Order {
        LEFT, // the complete part is to the left of the current word
        RIGHT, // the complete part is to the right of the current word
        BOTH // the complete part is an empty string, which is to the both sides
    };
    
    // hash function for a pair of integers
    struct hash {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        dict = unordered_map<string, int>();
        unordered_set<pair<int, int>, hash> result;
        
        // build up the dictionary (hash map)
        for (int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        
        string ans; // if the palindrome exists, find the complete part
        Order order; // the order of the complete part: left, right, or both
        
        // suppose the possible center is between positions p1 and p2 of the i-th word.
        auto proc = [&](int i, int p1, int p2) {
            if (get_palindrome_complete(words[i], ans, p1, p2, order)) {
                auto it = dict.find(ans);
                if (it != dict.end()) {
                    if (order == RIGHT || order == BOTH) {
                        if (i != it->second) {
                            result.insert(pair<int, int>(i, it->second));
                        }
                    }
                    if (order == LEFT || order == BOTH) {
                        if (i != it->second) {
                            result.insert(pair<int, int>(it->second, i));
                        }
                    }
                }
            }
        };
        
        // for each possible center of a palindrome
        for (int i = 0; i < words.size(); i++) {
            
            // if the center position is p
            for (int p = 0; p < words[i].size(); p++) {
                proc(i, p, p);
            }
            
            // if the center position is between (p - 1) and p
            for (int p = 0; p <= words[i].size(); p++) {
                proc(i, p - 1, p);
            }
        }
        
        vector<vector<int>> ret;
        for (auto it = result.begin(); it != result.end(); it++) {
            ret.push_back(vector<int>{(*it).first, (*it).second});
        }
        return ret;
    }
    
private:
    unordered_map<string, int> dict;
    
    bool get_palindrome_complete(const string &s, string &ans, int p1, int p2, Order &order) {
        while (p1 >= 0 && p2 < s.size()) {
            if (s[p1] != s[p2]) {
                return false;
            }
            p1--;
            p2++;
        }
        
        if (p1 < 0 && p2 >= s.size()) {
            ans = "";
            order = BOTH;
        } else if (p2 >= s.size()) {
            ans = s.substr(0, p1 + 1);
            reverse(ans.begin(), ans.end());
            order = RIGHT;
        } else /* if (p1 < 0) */ {
            ans = s.substr(p2, s.size() - p2);
            reverse(ans.begin(), ans.end());
            order = LEFT;
        }
        
        return true;
    }
};