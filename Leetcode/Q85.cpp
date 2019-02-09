class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        // To ensure all 1's in the monotonic stacks can be popped, insert 0's at the back of each row.
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].push_back('0');
        }
        
        // First, for each row,
        // obtain the number of consecutive 1's on the right side of each element using a monotonic stack.
        // These numbers (stored in nums) form a histogram for each column
        
        vector<vector<int>> nums = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        for (int i = 0; i < matrix.size(); i++) {
            stack<int> monoStack;
            for (int j = 0; j < matrix[0].size(); j++) {
                while (!monoStack.empty() && matrix[i][monoStack.top()] > matrix[i][j]) {
                    nums[i][monoStack.top()] = j - monoStack.top();
                    monoStack.pop();
                }
                monoStack.push(j);
            }
        }
        
        // Second, for each column,
        // solve the maximal rectangle in the histogram using the idea of Problem 84 (largest rectangle in histogram)
        
        int result = 0;
        for (int j = 0; j < matrix[0].size(); j++) {
            vector<int> column = vector<int>(nums.size());
            for (int i = 0; i < matrix.size(); i++) {
                column[i] = nums[i][j];
            }
            
            SolutionProblem84 solve;
            int area = solve.largestRectangleArea(column);
            result = max(result, area);
        }
        return result;
    }
    
private:
    static int max(int a, int b) {
        return a > b ? a : b;
    }
    
    class SolutionProblem84 {
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
};