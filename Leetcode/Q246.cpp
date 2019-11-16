class Solution {
public:
    bool isStrobogrammatic(string num) {
        auto map = unordered_map<char, char> {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        int i = 0;
        int j = num.size() - 1;
        while (i <= j) {
            if (map.find(num[i]) == map.end() || map.at(num[i]) != num[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
