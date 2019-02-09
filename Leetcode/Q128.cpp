class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> nums_set;
        for (int num : nums) {
            nums_set.insert(num);
        }
        
        int result = 0;
        for (int num : nums) {
            if (nums_set.find(num - 1) == nums_set.end()) {
                int i = 1;
                while (nums_set.find(num + i) != nums_set.end()) {
                    i++;
                }
                result = max<int>(result, i);
            }
        }
        
        return result;
    }
    
private:
    template <typename T>
    T max(T a, T b) {
        return (a < b) ? b : a;
    }
};