class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        this->map = unordered_map<char, char>{
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        string num = string(n, 'x');
        vector<string> result;
        help(num, 0, result);
        return result;
    }
    
private:
    unordered_map<char, char> map;
    void help(string& num, int i, vector<string>& result) {
        int j = num.size() - 1 - i;
        if (i > j) {
            if (num.size() <= 1 || num[0] != '0') {
                result.push_back(num);
            }
            return;
        }
        for (auto it = this->map.begin(); it != this->map.end(); ++it) {
            if (i < j) {
                num[i] = it->first;
                num[j] = it->second;
            } else if (it->first != it->second) {
                continue;
            } else {
                num[i] = it->first;
            }
            help(num, i + 1, result);
        }
    }
};
