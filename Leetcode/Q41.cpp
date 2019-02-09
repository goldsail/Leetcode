class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> nums_set;
        for (int num : nums) {
            if (num > 0) {
                nums_set.insert(num);
            }
        }
        nums_set.insert(0);
        
        int result = INT_MAX;
        for (int num : nums_set) {
            if (nums_set.find(num + 1) == nums_set.end()) {
                result = min(result, num + 1);
            }
        }
        
        return result;
    }
    
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
};