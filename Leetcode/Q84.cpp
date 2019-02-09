class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // Claim: The area of largest rectangle starting from index i depends on next[i] and prev[i], where
        // next[i] is the index of the next element smaller than heights[i], and
        // prev[i] is the index of the last element smaller than heights[i].
        // Initially, set next[i] = heights.size() as we do not know where the next smaller element is.
        // Initially, set prev[i] = -1 as we do not know where the last smaller element is.
        vector<int> next = vector<int>(heights.size(), heights.size());
        vector<int> prev = vector<int>(heights.size(), -1);
        
        // We maintain a monotonic stack which stores indices of which the heights ascend from bottom to top.
        stack<int> monoStack;
        
        // First, scan from left to right. 
        // Update next[j] when j is popped from the monotonic stack, indicating a "next smaller element".
        monoStack = stack<int>();
        for (int i = 0; i < heights.size(); i++) {
            while (!monoStack.empty() && heights[monoStack.top()] > heights[i]) {
                next[monoStack.top()] = i;
                monoStack.pop();
            }
            monoStack.push(i);
        }
        
        // Second, scan from right to left. 
        // Update prev[j] when j is popped from the monotonic stack, indicating a "last smaller element".
        monoStack = stack<int>();
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!monoStack.empty() && heights[monoStack.top()] > heights[i]) {
                prev[monoStack.top()] = i;
                monoStack.pop();
            }
            monoStack.push(i);
        }
        
        // Then, using next[i] and prev[i], calculate the area of the largest rectangle starting from index i
        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int area = heights[i] * (next[i] - prev[i] - 1);
            result = max(result, area);
        }
        return result;
    }
    
private:
    static int min(int a, int b) {
        return a < b ? a : b;
    }
    
    static int max(int a, int b) {
        return a > b ? a : b;
    }
};