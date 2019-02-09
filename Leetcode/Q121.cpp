class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 1. obtain indices of next greater numbers using a monotonic stack
        stack<int> mono_stack;
        vector<int> next_greaters = vector<int>(prices.size(), prices.size());
        
        for (int i = 0; i < prices.size(); i++) {
            while (!mono_stack.empty() && prices[i] > prices[mono_stack.top()]) {
                next_greaters[mono_stack.top()] = i;
                mono_stack.pop();
            }
            mono_stack.push(i);
        }
        
        // 2. convert next greater numbers to next greatest numbers using a stack
        vector<int> next_greatests = vector<int>(prices.size(), -1);
        for (int i = 0; i < prices.size(); i++) {
            if (next_greatests[i] < 0) {
                
                // starting from i, push greater numbers in a stack
                stack<int> stk;
                int j = i;
                do {
                    stk.push(j);
                    j = next_greaters[j];
                } while (j < prices.size());
                
                // for each index in the stack, its next greatest is obtained
                int greatest_index = stk.top();
                while (!stk.empty()) {
                    if (stk.top() == greatest_index) {
                        next_greatests[stk.top()] = prices.size();
                    } else {
                        next_greatests[stk.top()] = greatest_index;
                    }
                    stk.pop();
                }
                
            }
        }
        
        // 3. obtain the profits
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (next_greatests[i] < prices.size()) {
                result = max(result, prices[next_greatests[i]] - prices[i]);
            }
        }
        return result;
    }
};