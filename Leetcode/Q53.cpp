class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // return divideAndConquer(nums.begin(), nums.end());
        return dynamicProgramming(nums);
    }
    
private:
    int divideAndConquer(vector<int>::iterator start, vector<int>::iterator end) {
        if (end - start == 0) return 0;
        if (end - start == 1) return start[0];
        vector<int>::iterator mid = start + (end - start) / 2;
        int leftSum = divideAndConquer(start, mid);
        int rightSum = divideAndConquer(mid, end);
        
        int crossSumLeft = numeric_limits<int>::min();
        {
            int sum = 0;
            for (auto it = mid; it != start; --it) {
                sum += it[-1];
                crossSumLeft = max(crossSumLeft, sum);
            }
        }
        
        int crossSumRight = numeric_limits<int>::min();
        {
            int sum = 0;
            for (auto it = mid; it != end; ++it) {
                sum += it[0];
                crossSumRight = max(crossSumRight, sum);
            }
        }
        
        return max(max(leftSum, rightSum), crossSumLeft + crossSumRight);
    }
    
    int dynamicProgramming(const vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = nums.front();
        int currSum = nums.front(); // max-sum subarray ending at current position
        
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            currSum = max(currSum + it[0], it[0]);
            result = max(result, currSum);
        }
        return result;
    }
};
