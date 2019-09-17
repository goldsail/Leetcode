class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        
        unordered_set<string> visited;
        queue<pair<string, int>> que;
        int maxDepth = s.size();
        visited.insert(s);
        que.push(make_pair(s, 0));
        
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            if (curr.second > maxDepth) break;
            
            if (isValid(curr.first)) {
                maxDepth = curr.second;
                result.push_back(curr.first);
                continue;
            }
            
            for (int i = 0; i < curr.first.size(); i++) {
                string temp = curr.first.substr(0, i) + curr.first.substr(i + 1);
                if (visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    que.push(make_pair(temp, curr.second + 1));
                }
            }
        }
        
        return result;
    }
    
private:
    bool isValid(const string &s) {
        int stk = 0;
        for (char c : s) {
            switch (c) {
                case '(':
                    stk++;
                    break;
                case ')':
                    stk--;
                    break;
            }
            if (stk < 0) return false;
        }
        return stk == 0;
    }
};

