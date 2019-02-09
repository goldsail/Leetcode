class Solution {
public:
    int longestValidParentheses(string s) {
        
        identifyValidParentheses(s);
        
        return findLongest(s);
    }
    
private:
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    void identifyValidParentheses(string &s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    s[i] = '-';
                    s[stk.top()] = '-';
                    stk.pop();
                }
            } else {
                throw "error";
            }
        }
    }
    
    int findLongest(const string &s) {
        int result = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                count++;
            } else {
                count = 0;
            }
            result = max(result, count);
        }
        return result;
    }
};