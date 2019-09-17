class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // dpMax[i] means the max-product subarray ending in position i
        vector<int> dpMax(nums.size());
        // dpMin[i] means the min-product subarray ending in position i
        vector<int> dpMin(nums.size());
        
        // initialize
        
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        
        // dynamic programming
        
        for (int i = 1; i < nums.size(); i++) {
            dpMax[i] = max(nums[i], 
                           max(dpMax[i - 1] * nums[i], 
                               dpMin[i - 1] * nums[i]));
            dpMin[i] = min(nums[i], 
                           min(dpMax[i - 1] * nums[i], 
                               dpMin[i - 1] * nums[i]));
        }
        
        // get result
        return *max_element(dpMax.begin(), dpMax.end());
    }
};

